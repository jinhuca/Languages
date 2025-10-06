namespace P093;
public static class ChatExtensions
{
  public static IObservable<string> ToObservable(this IChatConnection connection)
  {
    return new ObservableConnection(connection);
  }
}