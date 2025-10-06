namespace D11_Flyweight
{
  public abstract class AbstractEngine : IEngine
  {

    private int size;
    private bool turbo;


    public AbstractEngine(int size, bool turbo)
    {
      this.size = size;
      this.turbo = turbo;
    }

    public virtual int Size
    {
      get
      {
        return size;
      }
    }

    public virtual bool Turbo
    {
      get
      {
        return turbo;
      }
    }

    public virtual void Diagnose(IDiagnosticTool tool)
    {
      tool.RunDiagnosis(this);
    }


    public override string ToString()
    {
      return GetType().Name + " (" + size + ")";
    }

  }
}
