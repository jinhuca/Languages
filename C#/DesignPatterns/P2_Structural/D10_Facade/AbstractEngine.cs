namespace D10Facade
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

    public virtual int Size => size;

    public virtual bool Turbo => turbo;

    public override string ToString() => GetType().Name + " (" + size + ")";
  }
}
