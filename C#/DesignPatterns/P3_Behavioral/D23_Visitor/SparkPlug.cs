namespace D23_Visitor
{
  public class SparkPlug
  {
    public virtual void AcceptEngineVisitor(IEngineVisitor visitor)
    {
      visitor.Visit(this);
    }
  }
}
