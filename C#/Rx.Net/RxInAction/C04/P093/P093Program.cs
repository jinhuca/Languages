using Helpers;

namespace P093;

internal class Program
{
  static void Main(string[] args)
  {
    var chatClient_ = new ChatClient();
    var connection_ = chatClient_.Connect("guest", "guest");

    IObservable<string> observableConnection_ = new ObservableConnection(connection_);
    var subscription_ = chatClient_
      .Connect("guest", "guest")
      .ToObservable()
      .SubscribeConsole();
    
    Console.ReadLine();
  }
}