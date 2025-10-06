using static System.Console;

namespace D05Singleton
{
  public class Program
  {
    public static void Main(string[] args)
    {
      WriteLine("next serial: " + SerialNumberGenerator.Instance.NextSerial);
      WriteLine("next serial: " + SerialNumberGenerator.Instance.NextSerial);
      WriteLine("next serial: " + SerialNumberGenerator.Instance.NextSerial);
    }
  }
}
