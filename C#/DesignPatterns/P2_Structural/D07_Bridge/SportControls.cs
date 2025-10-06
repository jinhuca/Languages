namespace D07Bridge
{
  public class SportControls : AbstractDriverControls
  {
    public SportControls(IEngine engine) : base(engine)
    {
    }

    public virtual void AccelerateHard()
    {
      Accelerate();
      Accelerate();
    }
  }
}
