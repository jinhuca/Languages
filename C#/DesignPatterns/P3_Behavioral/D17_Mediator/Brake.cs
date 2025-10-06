using System;
using static System.Console;

namespace D17_Mediator
{
  public class Brake
  {
    private readonly EngineManagementSystem _mediator;
    private bool _enabled;
    private bool _applied;

    // Constructor accepts mediator as an argument
    public Brake(EngineManagementSystem mediator)
    {
      _mediator = mediator;
      _enabled = false;
      _applied = false;
      mediator.RegisterBrake(this);
    }

    public virtual void Enable()
    {
      _enabled = true;
      _mediator.BrakeEnabled();
      WriteLine("Brakes enabled");
    }

    public virtual void Disable()
    {
      _enabled = false;
      _mediator.BrakeDisabled();
      WriteLine("Brakes disabled");
    }

    public virtual bool Enabled => _enabled;

    public virtual void Apply()
    {
      if (Enabled)
      {
        _applied = true;
        _mediator.BrakePressed();
        WriteLine("Now braking");
      }
    }

    private void Release()
    {
      if (Enabled)
      {
        _applied = false;
      }
    }
  }
}
