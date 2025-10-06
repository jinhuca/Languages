namespace P185BasicQueryOperators.Model;

internal class ChatMessageViewModel(ChatMessage m)
{
  public string MessageContent { get; set; } = m.Content;
  public User User { get; set; } = new User(m.Sender, m.Room);
  public string Room { get; set; } = m.Room;
  public override string ToString() => $"Room: {Room} , Message: \"{MessageContent}\" was sent by {User}";
}