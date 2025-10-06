namespace D02Builder
{
  public abstract class AbstractEngine : IEngine
  {
    protected AbstractEngine(int _size, bool _turbo)
    {
      Size = _size;
      Turbo = _turbo;
    }

    public virtual int Size { get; }
  
    public virtual bool Turbo { get; }

    public override string ToString() => GetType().Name + " (" + Size + ")";
  }
}
