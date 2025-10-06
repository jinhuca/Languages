namespace D19_Observer
{
  public class Program
  {
    public static void Main(string[] args)
    {
      // Create a speedometer...
      Speedometer speedo = new Speedometer();

      // Create a monitor...
      SpeedMonitor monitor = new SpeedMonitor(speedo);

      // Add automatic gearbox as an observer
      AutomaticGearbox auto = new AutomaticGearbox(speedo);

      // Drive at different speeds...
      speedo.CurrentSpeed = 50;
      speedo.CurrentSpeed = 70;
      speedo.CurrentSpeed = 40;
      speedo.CurrentSpeed = 100;
      speedo.CurrentSpeed = 69;
    }
  }
}
