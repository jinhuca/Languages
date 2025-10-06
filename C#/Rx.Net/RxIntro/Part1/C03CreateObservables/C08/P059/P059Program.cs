using System.Reactive.Subjects;

namespace P059;

internal class P059Program
{
  static void Main()
  {
    Console.WriteLine("Hello, World!");
  }
}

public class MessageQueueToRx : IDisposable
{
  private readonly Subject<string> messages = new();
  public IObservable<string> Messages => messages;

  public void Run()
  {
    while (true)
    {
      // Receive a message from some hypothetical message queuing service
      string message = MqLibrary.ReceiveMessage();
      messages.OnNext(message);
    }
  }

  public void Dispose()
  {
    messages.Dispose();
  }
}

public class MqLibrary
{
  internal static string ReceiveMessage()
  {
    throw new NotImplementedException();
  }
}