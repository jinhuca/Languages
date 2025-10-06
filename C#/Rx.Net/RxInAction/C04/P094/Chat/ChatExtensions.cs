namespace P094;

public static class ChatExtensions
{
  public static IObservable<string> ToObservable(this IChatConnectionEventAggregator connectionEventAggregator)
  {
    return new ChatConnectionObservable(connectionEventAggregator);
  }
}