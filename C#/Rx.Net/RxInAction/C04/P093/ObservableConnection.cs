using System.Reactive;
using System.Reactive.Disposables;

namespace P093;

public class ObservableConnection(IChatConnection chatConnection) : ObservableBase<string>
{
  protected override IDisposable SubscribeCore(IObserver<string> observer)
  {
    Action<string> received = observer.OnNext;
    Action closed = observer.OnCompleted;
    Action<Exception> error = observer.OnError;

    chatConnection.Received += received;
    chatConnection.Closed += closed;
    chatConnection.Error += error;

    observer.OnNext("Hello");
    observer.OnNext("Jon");
    observer.OnNext("How are you these days?");
    observer.OnCompleted();

    observer.OnNext("Bye");

    return Disposable.Create(() =>
    {
      chatConnection.Received -= received;
      chatConnection.Closed -= closed;
      chatConnection.Error -= error;
      chatConnection.Disconnect();
    });
  }
}