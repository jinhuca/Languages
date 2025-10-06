using static System.Console;

namespace D25_SimpleFactory
{
  public class ManualGearbox : Gearbox
  {
    public ManualGearbox()
    {
      WriteLine("New manual gearbox created");
    }
  }
}
