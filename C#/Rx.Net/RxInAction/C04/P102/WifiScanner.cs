namespace P102;

public delegate void NetworkFoundEventHandler(string ssid);
public delegate void ExtendedNetworkFoundEventHandler(string ssid, int strength);

internal class WifiScanner
{
  public event NetworkFoundEventHandler NetworkFound = delegate { };
  public event ExtendedNetworkFoundEventHandler ExtendedNetworkFound = delegate { };
  public event Action Connected = delegate { };

  public void RaiseFound(string ssid, int strength = 0)
  {
    NetworkFound(ssid);
    ExtendedNetworkFound(ssid, strength);
  }

  public void RaiseConnected() => Connected();
}