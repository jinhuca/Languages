using System;

namespace D23_Visitor
{
  public class EngineInventory : IEngineVisitor
  {
    private int camshaftCount;
    private int pistonCount;
    private int sparkPlugCount;

    public EngineInventory()
    {
      camshaftCount = 0;
      pistonCount = 0;
      sparkPlugCount = 0;
    }

    public virtual void Visit(Camshaft camshaft)
    {
      camshaftCount++;
    }

    public virtual void Visit(IEngine engine)
    {
      Console.WriteLine("The engine has: " +
            camshaftCount + " camshaft(s), " +
            pistonCount + " piston(s), and " +
            sparkPlugCount + " spark plug(s)");
    }

    public virtual void Visit(Piston piston)
    {
      pistonCount++;
    }

    public virtual void Visit(SparkPlug sparkPlug)
    {
      sparkPlugCount++;
    }

  }
}
