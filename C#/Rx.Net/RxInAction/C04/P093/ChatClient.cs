namespace P093;

public class ChatClient
{
  private readonly IList<IChatConnection> _connections = new List<IChatConnection>();

  public IChatConnection Connect(string user, string password)
  {
    var chatConnection_ = new ChatConnection();
    _connections.Add(chatConnection_);
    return chatConnection_;
  }
}