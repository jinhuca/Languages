using System.Reactive.Subjects;
using Helpers;

namespace P165;

enum NetworkConnectivity
{
  Connected,
  Disconnected
}

internal class P165Program
{
  static void Main(string[] args)
  {
    BehaviorSubjectExample();
  }

  static void BehaviorSubjectExample()
  {
    BehaviorSubject<NetworkConnectivity> connection = new BehaviorSubject<NetworkConnectivity>(NetworkConnectivity.Disconnected);
    connection.SubscribeConsole("first");
    connection.OnNext(NetworkConnectivity.Connected);
    connection.SubscribeConsole("second");
    Console.WriteLine($"connection is {connection.Value}");
  }
}