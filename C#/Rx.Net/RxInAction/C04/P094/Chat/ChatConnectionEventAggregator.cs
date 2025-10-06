namespace P094;
using static System.Console;

public class ChatConnectionEventAggregator : IChatConnectionEventAggregator
{
  public event Action<string> Received = delegate { };
  public event Action Closed = delegate { };
  public event Action<Exception> Error = delegate { };

  public void NotifyReceived(string msg)
  {
    Received(msg);
  }

  public void NotifyClosed()
  {
    Closed();
  }

  public void NotifyError()
  {
    Error(new OutOfMemoryException());
  }

  public void Disconnect()
  {
    WriteLine("Disconnect");
  }
}