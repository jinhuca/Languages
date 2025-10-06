namespace P031;

public class RxFsEventsMultiSubscriber : IObservable<FileSystemEventArgs>
{
  private readonly object sync = new();
  private readonly List<Subscription> subscribers = new();
  private readonly FileSystemWatcher watcher;

  public RxFsEventsMultiSubscriber(string folder)
  {
    watcher = new FileSystemWatcher(folder);

    watcher.Created += SendEventToObservers;
    watcher.Changed += SendEventToObservers;
    watcher.Renamed += SendEventToObservers;
    watcher.Deleted += SendEventToObservers;

    watcher.Error += SendErrorToObservers;
  }

  public IDisposable Subscribe(IObserver<FileSystemEventArgs> observer)
  {
    Subscription sub = new(this, observer);
    lock (sync)
    {
      subscribers.Add(sub);

      if (subscribers.Count == 1)
      {
        // We had no subscribers before, but now we've got one, so we need
        // to start up the FileSystemWatcher.
        watcher.EnableRaisingEvents = true;
      }
    }

    return sub;
  }

  private void Unsubscribe(Subscription sub)
  {
    lock (sync)
    {
      subscribers.Remove(sub);

      if (subscribers.Count == 0)
      {
        watcher.EnableRaisingEvents = false;
      }
    }
  }

  void SendEventToObservers(object _, FileSystemEventArgs e)
  {
    lock (sync)
    {
      foreach (var subscription in subscribers)
      {
        subscription.Observer.OnNext(e);
      }
    }
  }

  void SendErrorToObservers(object _, ErrorEventArgs e)
  {
    Exception x = e.GetException();
    lock (sync)
    {
      foreach (var subscription in subscribers)
      {
        subscription.Observer.OnError(x);
      }

      subscribers.Clear();
    }
  }

  private class Subscription : IDisposable
  {
    private RxFsEventsMultiSubscriber? parent;

    public Subscription(
      RxFsEventsMultiSubscriber rxFsEventsMultiSubscriber, 
      IObserver<FileSystemEventArgs> observer)
    {
      parent = rxFsEventsMultiSubscriber;
      Observer = observer;
    }

    public IObserver<FileSystemEventArgs> Observer { get; }

    public void Dispose()
    {
      parent?.Unsubscribe(this);
      parent = null;
    }
  }
}