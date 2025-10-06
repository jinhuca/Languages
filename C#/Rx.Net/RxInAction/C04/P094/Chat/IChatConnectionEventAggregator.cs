namespace P094;

public interface IChatConnectionEventAggregator
{
  event Action<string> Received;
  event Action Closed;
  event Action<Exception> Error;

  void Disconnect();

  #region Testing Utils

  void NotifyClosed();
  void NotifyError();
  void NotifyReceived(string msg);

  #endregion
}