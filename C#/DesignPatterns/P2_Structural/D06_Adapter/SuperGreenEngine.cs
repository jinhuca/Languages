namespace D06Adapter
{
  public class SuperGreenEngine
  {
    private readonly int _size;

    public SuperGreenEngine(int size) => _size = size;

    public virtual int EngineSize => _size;

    public override string ToString() => "SUPER ENGINE " + _size;
  }
}
