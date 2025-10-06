namespace D12_Proxy
{
  public class Program
  {
    public static void Main(string[] args)
    {
      IEngine engine = new EngineProxy(1300, false);
      engine.Diagnose(new EngineDiagnosticTool());
    }
  }
}
