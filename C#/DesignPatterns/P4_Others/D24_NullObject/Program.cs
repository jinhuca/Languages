namespace D24_NullObject
{
  public class Program
  {
    public static void Main(string[] args)
    {
      IWarningLight[] lights = new IWarningLight[3];
      lights[0] = new OilLevelLight();
      lights[1] = new BrakeFluidLight();
      lights[2] = new NullObjectLight(); // empty slot

      // No need to test for null...
      foreach (IWarningLight currentLight in lights)
      {
        currentLight.On();
        currentLight.Off();
      }
    }
  }
}
