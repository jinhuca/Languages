using System.Reactive.Linq;

namespace P102OneParam;

internal class Program
{
  static void Main(string[] args)
  {
    var wifiScanner = new WifiScanner();
    
    var connectionObservable = 
      Observable.FromEvent<NetworkFoundEventHandler, string>(
      h => wifiScanner.NetworkFound += h,
      h => wifiScanner.NetworkFound -= h);

    connectionObservable.Subscribe(evt =>
      {
        Console.WriteLine(evt);
      },
      ex =>
      {
        Console.WriteLine(ex.Message);
      },
      () =>
      {
        Console.WriteLine("Completed");
      });

    wifiScanner.RaiseConnected("321");
  }
}