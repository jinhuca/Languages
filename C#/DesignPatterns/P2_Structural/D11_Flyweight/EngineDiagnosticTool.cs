using System.Threading;
using static System.Console;

namespace D11_Flyweight
{
  public class EngineDiagnosticTool : IDiagnosticTool
  {
    public virtual void RunDiagnosis(object obj)
    {
      WriteLine($"Starting engine diagnostic tool for {obj}");
      Thread.Sleep(5000);
      WriteLine("Engine diagnosis complete");
    }
  }
}
