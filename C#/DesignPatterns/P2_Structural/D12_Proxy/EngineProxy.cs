using System;
using System.Threading;

namespace D12_Proxy
{
  public class EngineProxy : IEngine
  {
    private IEngine engine;

    public EngineProxy(int size, bool turbo)
    {
      if (turbo)
      {
        engine = new TurboEngine(size);
      }
      else
      {
        engine = new StandardEngine(size);
      }
    }

    public virtual int Size
    {
      get
      {
        return engine.Size;
      }
    }

    public virtual bool Turbo
    {
      get
      {
        return engine.Turbo;
      }
    }

    // This method is time-consuming...
    public virtual void Diagnose(IDiagnosticTool tool)
    {
      Console.WriteLine("(Running tool as thread)");
      Thread t = new Thread(() => RunDiagnosticTool(tool));
      t.Start();
      Console.WriteLine("EngineProxy diagnose() method finished");
    }

    public virtual void RunDiagnosticTool(IDiagnosticTool tool)
    {
      tool.RunDiagnosis(this);
    }

  }
}
