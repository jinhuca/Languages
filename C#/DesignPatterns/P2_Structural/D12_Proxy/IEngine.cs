namespace D12_Proxy
{
  public interface IEngine
  {
    // Methods having intrinsic (i.e. shared) state
    int Size { get; }
    bool Turbo { get; }

    // Methods having extrinsic (i.e. unshared) state
    void Diagnose(IDiagnosticTool tool);
  }
}
