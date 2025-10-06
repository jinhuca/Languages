namespace D02Builder
{
  public abstract class VehicleBuilder
  {
    public virtual void BuildBody() { }
    public virtual void BuildBoot() { }
    public virtual void BuildChassis() { }
    public virtual void BuildPassengerArea() { }
    public virtual void BuildReinforcedStorageArea() { }
    public virtual void BuildWindow() { }
    public abstract IVehicle Vehicle { get; }
  }
}
