namespace P094;

using Helpers;
using static System.Console;

static class ChatExample
{
  public static void Run()
  {
    var chatClient = new ChatClient();
    var subscription = CreateObservableConnection(chatClient);
    //var subscription = CreateObservableConnectionFluently(chatClient);
    //var subscription = CreateDeferredObservableConnection(chatClient);

    //while (true)
    //{
    //  WriteLine("write a message to be sent, E for error, or X to exit");
    //  var msg = ReadLine();
    //  if (msg == "X")
    //  {
    //    chatClient.NotifyClosed();
    //    break;
    //  }
    //  if (msg == "E")
    //  {
    //    chatClient.NotifyError();
    //  }

    //  chatClient.NotifyReceived(msg);
    //}
  }

  private static IDisposable CreateObservableConnection(ChatClient chatClient)
  {
    var connection = chatClient.Connect("guest", "guest");
    IObservable<string> observableConnection = new ChatConnectionObservable(connection);
    var subscription = observableConnection.SubscribeConsole("reciever");

    return subscription;
  }

  private static IDisposable CreateObservableConnectionFluently(ChatClient chatClient)
  {
    var subscription =
      chatClient.Connect("guest", "guest")
        .ToObservable()
        .SubscribeConsole();

    return subscription;
  }

  private static IDisposable CreateDeferredObservableConnection(ChatClient chatClient)
  {
    var messages = chatClient.ObserveMessagesDeferred("user", "password");
    WriteLine("Press Enter to subscribe to the deferred observable");
    ReadLine();
    var subscription = messages.SubscribeConsole();
    var subscription2 = messages.SubscribeConsole();

    return subscription;
  }
}