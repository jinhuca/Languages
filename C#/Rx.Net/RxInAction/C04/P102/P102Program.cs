using Helpers;
using System.Reactive.Linq;
using static System.Console;

namespace P102;

file class P102Program
{
  static void Main(string[] args)
  {
    ConvertFromEventWithoutArgument();
    //ConvertFromEvent();
  }

  private static void ConvertFromEventWithoutArgument()
  {
    WriteLine("Converting events without arguments.");
    var wifiScanner = new WifiScanner();
    var connected = Observable.FromEvent(h => wifiScanner.Connected += h, h => wifiScanner.Connected -= h);
    connected.SubscribeConsole("connected");
    wifiScanner.RaiseConnected();
  }

  private static void ConvertFromEvent()
  {
    WriteLine("Converting Non Standard Events.");
    var wifiScanner = new WifiScanner();
    IObservable<(string, int)> networks = Observable.FromEvent<ExtendedNetworkFoundEventHandler, (string, int)>(
      rxHandler => (ssid, strength) => rxHandler((ssid, strength)),
      h => wifiScanner.ExtendedNetworkFound += h,
      h => wifiScanner.ExtendedNetworkFound -= h);
    networks.SubscribeConsole();
    while (true)
    {
      WriteLine("Enter the network ssid or X to exit");
      var ssid = ReadLine();
      if (ssid == "X")
      {
        break;
      }

      WriteLine("Enter the network strength: 1 to 10");
      var strength = int.Parse(ReadLine() ?? string.Empty);
      wifiScanner.RaiseFound(ssid, strength);
    }
  }
}