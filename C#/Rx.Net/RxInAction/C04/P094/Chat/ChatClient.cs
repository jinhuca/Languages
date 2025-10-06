using System.Reactive.Linq;
using static System.Console;

namespace P094;

internal class ChatClient
{
  readonly IList<IChatConnectionEventAggregator> _connections = new List<IChatConnectionEventAggregator>();

  public IChatConnectionEventAggregator Connect(string user, string password)
  {
    WriteLine("Connect");
    var chatConnection = new ChatConnectionEventAggregator();
    _connections.Add(chatConnection);
    return chatConnection;
  }


  public IObservable<string> ObserveMessages(string user, string password)
  {
    var connection = Connect(user, password);
    return connection.ToObservable();
  }

  public IObservable<string> ObserveMessagesDeferred(string user, string password)
  {
    return Observable.Defer(() =>
    {
      var connection = Connect(user, password);
      return connection.ToObservable();
    });
  }

  #region Testing Utils

  public void NotifyReceived(string msg)
  {
    foreach (var chatConnection in _connections)
    {
      chatConnection.NotifyReceived(msg);
    }
  }

  public void NotifyClosed()
  {
    foreach (var chatConnection in _connections)
    {
      chatConnection.NotifyClosed();
    }
  }

  public void NotifyError()
  {
    foreach (var chatConnection in _connections)
    {
      chatConnection.NotifyError();
    }
  }

  #endregion
}