using static System.Console;

namespace D17_Mediator
{
  public class Ignition
  {
    private readonly EngineManagementSystem _mediator;
    private bool _on;

    // Constructor accepts mediator as an argument
    public Ignition(EngineManagementSystem mediator)
    {
      _mediator = mediator;
      _on = false;

      // Register back with the mediator;
      mediator.RegisterIgnition(this);
    }

    public virtual void Start()
    {
      _on = true;
      _mediator.IgnitionTurnedOn();
      WriteLine("Ignition turned on");
    }

    public virtual void Stop()
    {
      _on = false;
      _mediator.IgnitionTurnedOff();
      WriteLine("Ignition turned off");
    }
    public virtual bool On => _on;
  }
}
