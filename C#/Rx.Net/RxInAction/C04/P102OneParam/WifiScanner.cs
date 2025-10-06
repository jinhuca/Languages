namespace P102OneParam;

public delegate void NetworkFoundEventHandler(string ssid);

internal class WifiScanner
{
  public event NetworkFoundEventHandler NetworkFound = null!;
  public void RaiseConnected(string ssid) => NetworkFound(ssid);
}