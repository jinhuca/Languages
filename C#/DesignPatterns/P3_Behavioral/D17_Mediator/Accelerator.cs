using System;

namespace D17_Mediator
{
  public class Accelerator
  {
    private readonly EngineManagementSystem _mediator;
    private bool _enabled;
    private int _speed;

    // Constructor accepts mediator as an argument
    public Accelerator(EngineManagementSystem mediator)
    {
      _mediator = mediator;
      _enabled = false;
      mediator.RegisterAccelerator(this);
    }

    public virtual void Enable()
    {
      _enabled = true;
      _mediator.AcceleratorEnabled();
      Console.WriteLine("Accelerator enabled");
    }

    public virtual void Disable()
    {
      _enabled = false;
      _mediator.AcceleratorDisabled();
      Console.WriteLine("Accelerator disabled");
    }

    public virtual bool Enabled => _enabled;

    public virtual void AccelerateToSpeed(int speed)
    {
      if (Enabled)
      {
        _speed = speed;
        Console.WriteLine("Speed now " + Speed);
      }
    }
    public virtual int Speed => _speed;
  }
}
