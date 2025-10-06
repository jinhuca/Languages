namespace D23_Visitor
{
  public interface IEngine
  {
    int Size { get; }
    bool Turbo { get; }

    void AcceptEngineVisitor(IEngineVisitor visitor);
  }
}
