using System;

namespace D23_Visitor
{
  public class Program
  {
    public static void Main(string[] args)
    {
      // Create an engine...
      IEngine engine = new StandardEngine(1300);

      // Run diagnostics on the engine...
      engine.AcceptEngineVisitor(new EngineDiagnostics());

      // Run inventory on the engine...
      engine.AcceptEngineVisitor(new EngineInventory());

      Console.Read();
    }
  }
}
