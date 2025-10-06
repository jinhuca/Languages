namespace D04Prototype
{
  public abstract class AbstractEngine : IEngine
  {
    private readonly int _size;
    private readonly bool _turbo;

    protected AbstractEngine(int size, bool turbo)
    {
      _size = size;
      _turbo = turbo;
    }

    public virtual int Size => _size;
    public virtual bool Turbo => _turbo;
    public override string ToString() => GetType().Name + " (" + _size + ")";
  }
}
