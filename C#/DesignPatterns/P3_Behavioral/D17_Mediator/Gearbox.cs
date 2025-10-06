using static System.Console;

namespace D17_Mediator
{
  public class Gearbox
  {
    private readonly EngineManagementSystem _mediator;
    private bool _enabled;
    private Gear _currentGear;

    // Constructor accepts mediator as an argument
    public Gearbox(EngineManagementSystem mediator)
    {
      _mediator = mediator;
      _enabled = false;
      _currentGear = Gear.Neutral;
      mediator.RegisterGearbox(this);
    }

    public virtual void Enable()
    {
      _enabled = true;
      _mediator.GearboxEnabled();
      WriteLine("Gearbox enabled");
    }

    public virtual void Disable()
    {
      _enabled = false;
      _mediator.GearboxDisabled();
      WriteLine("Gearbox disabled");
    }

    public virtual bool Enabled => _enabled;

    public virtual Gear Gear
    {
      set
      {
        if (Enabled && Gear != value)
        {
          _currentGear = value;
          _mediator.GearChanged();
          WriteLine("Now in " + Gear + " gear");
        }
      }
      get => _currentGear;
    }

  }
}
