namespace D23_Visitor
{
  public class Piston
  {
    public virtual void AcceptEngineVisitor(IEngineVisitor visitor)
    {
      visitor.Visit(this);
    }
  }
}
