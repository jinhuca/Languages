namespace D23_Visitor
{
  public abstract class AbstractEngine : IEngine
  {
    private int size;
    private bool turbo;

    private Camshaft camshaft;
    private Piston piston;
    private SparkPlug[] sparkPlugs;

    public AbstractEngine(int size, bool turbo)
    {
      this.size = size;
      this.turbo = turbo;

      // Create a camshaft, piston and 4 spark plugs...
      camshaft = new Camshaft();
      piston = new Piston();
      sparkPlugs = new SparkPlug[]
              {
                      new SparkPlug(), new SparkPlug(),
                      new SparkPlug(), new SparkPlug()
              };
    }

    public virtual int Size => size;

    public virtual bool Turbo => turbo;

    public virtual void AcceptEngineVisitor(IEngineVisitor visitor)
    {
      // Visit each component first...
      camshaft.AcceptEngineVisitor(visitor);
      piston.AcceptEngineVisitor(visitor);
      foreach (SparkPlug eachSparkPlug in sparkPlugs)
      {
        eachSparkPlug.AcceptEngineVisitor(visitor);
      }

      // Now visit the receiver...
      visitor.Visit(this);
    }

    public override string ToString() => GetType().Name + " (" + size + ")";
  }
}
