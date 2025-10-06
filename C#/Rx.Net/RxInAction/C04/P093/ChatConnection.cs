namespace P093;

public class ChatConnection : IChatConnection
{
  public event Action<string>? Received = delegate{};
  public event Action? Closed = delegate { };
  public event Action<Exception>? Error = delegate { };
  public void Disconnect() { }
}