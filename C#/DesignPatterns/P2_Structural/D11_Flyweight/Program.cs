using static System.Console;

namespace D11_Flyweight
{
  public class Program
  {
    public static void Main(string[] args)
    {
      // Create the flyweight factory...
      EngineFlyweightFactory factory = new EngineFlyweightFactory();

      // Create the diagnostic tool
      IDiagnosticTool tool = new EngineDiagnosticTool();

      // Get the flyweights and run diagnostics on them
      IEngine standard1 = factory.GetStandardEngine(1300);
      standard1.Diagnose(tool);

      IEngine standard2 = factory.GetStandardEngine(1300);
      standard2.Diagnose(tool);

      IEngine standard3 = factory.GetStandardEngine(1300);
      standard3.Diagnose(tool);

      IEngine standard4 = factory.GetStandardEngine(1600);
      standard4.Diagnose(tool);

      IEngine standard5 = factory.GetStandardEngine(1600);
      standard5.Diagnose(tool);

      // Show that objects are shared
      WriteLine(standard1.GetHashCode());
      WriteLine(standard2.GetHashCode());
      WriteLine(standard3.GetHashCode());
      WriteLine(standard4.GetHashCode());
      WriteLine(standard5.GetHashCode());
    }
  }
}
