using System;

namespace D23_Visitor
{
  public class EngineDiagnostics : IEngineVisitor
  {
    public virtual void Visit(Camshaft camshaft)
    {
      Console.WriteLine("Diagnosing the camshaft");
    }

    public virtual void Visit(IEngine engine)
    {
      Console.WriteLine("Diagnosing the engine");
    }

    public virtual void Visit(Piston piston)
    {
      Console.WriteLine("Diagnosing the piston");
    }

    public virtual void Visit(SparkPlug sparkPlug)
    {
      Console.WriteLine("Diagnosing a single spark plug");
    }

  }
}
