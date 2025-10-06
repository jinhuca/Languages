namespace D23_Visitor
{
  public class Camshaft
  {
    public virtual void AcceptEngineVisitor(IEngineVisitor visitor)
    {
      visitor.Visit(this);
    }
  }
}
