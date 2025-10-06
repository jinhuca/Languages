using System.Reactive;
using System.Reactive.Disposables;
using Helpers;
using static System.Console;

namespace P094SimpleClient;

internal class P094SimpleProgram
{
  static void Main(string[] args)
  {
    var chatClient = new ChatClient();
    var connection = chatClient.Connect("guest", "guest");
    var observableConnection = new ObservableConnection(connection);
    var subscriptionX = observableConnection.SubscribeConsole("ConsoleObserver");

    ReadLine();
    subscriptionX.Dispose();
  }
}

//public interface IChatConnection
//{
//  event Action<string> Received;
//  event Action Closed;
//  event Action<Exception> Error;
//}

public class ChatConnection
{
  public event EventHandler<string>? Received;
  protected virtual void OnReceived(string message) => Received?.Invoke(this, message);

  public event EventHandler? Closed;
  protected virtual void OnClosed() => Closed?.Invoke(this, null);

  public event EventHandler<Exception>? Error;
  protected virtual void OnError(Exception error) => Error?.Invoke(this, error);

  //public void Disconnect() { Closed?.Invoke(); }

  public void ReceiveMessage(string message)
  {
    Received?.Invoke(this, message);
  }

  public void Close()
  {
    ReceiveMessage("This connection is closed now.");
    Closed?.Invoke(this, null);
  }

  public void NotifyError(Exception ex)
  {
    Error?.Invoke(this, ex);
  }
}

public class ObservableConnection : ObservableBase<string>
{
  private readonly ChatConnection _chatConnection;

  public ObservableConnection(ChatConnection chatConnection)
  {
    _chatConnection = chatConnection;
  }

  /// <summary>
  /// This override is to map events to observer methods inside SubscribeCore method.
  /// </summary>
  /// <param name="observer"></param>
  /// <returns></returns>
  protected override IDisposable SubscribeCore(IObserver<string> observer)
  {
    EventHandler<string>? received = (sender, msg) => { observer.OnNext(msg); };
    EventHandler<Exception>? error = (sender, error) => { observer.OnError(error); };
    EventHandler? closed = (sender, _) => { observer.OnCompleted(); };

    //closed = observer.OnCompleted;
    //Action<Exception> error = observer.OnError;

    _chatConnection.Received += received;
    _chatConnection.Closed += closed;
    _chatConnection.Error += error;

    //_chatConnection.Disconnect();


    _chatConnection.ReceiveMessage("Jon");
    _chatConnection.ReceiveMessage("How are you?");
    //_chatConnection.Close();
    //_chatConnection.OnError(new IOException());
    //received.Invoke("Hi");      // received -> observer.OnNext()
    //observer.OnNext("Hello");
    //closed();                   // closed -> observer.OnCompleted()
    //observer.OnNext($"Jon");
    //observer.OnNext("How are you these days?");
    //observer.OnCompleted();
    _chatConnection.ReceiveMessage("Bye");   

    return Disposable.Create(() =>
    {
      _chatConnection.Received -= received;
      _chatConnection.Closed -= closed;
      _chatConnection.Error -= error;
      _chatConnection.Close();
    });
  }

  public void PushMessages()
  {
    _chatConnection.ReceiveMessage("Hello");
  }
}

public class ChatClient
{
  public ChatConnection Connect(string user, string password)
  {
    return new ChatConnection();
  }
}

public static class ChatExtensions
{
  public static IObservable<string> ToObservable(this ChatConnection chatConnection)
  {
    var connection = new ObservableConnection(chatConnection);
    connection.PushMessages();
    return connection;
  }
}