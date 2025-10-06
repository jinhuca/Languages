namespace D07Bridge
{
  public class AbstractDriverControls
  {
    private IEngine engine;

    public AbstractDriverControls(IEngine engine)
    {
      this.engine = engine;
    }

    public virtual void IgnitionOn()
    {
      engine.Start();
    }

    public virtual void IgnitionOff()
    {
      engine.Stop();
    }

    public virtual void Accelerate()
    {
      engine.IncreasePower();
    }

    public virtual void Brake()
    {
      engine.DecreasePower();
    }

  }
}
