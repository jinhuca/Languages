using System;
using static System.Console;

namespace D17_Mediator
{
  public class EngineManagementSystem
  {
    private Ignition _ignition;
    private Gearbox _gearbox;
    private Accelerator _accelerator;
    private Brake _brake;

    private int currentSpeed;

    public EngineManagementSystem()
    {
      currentSpeed = 0;
    }

    // Methods that enable registration with this mediator...
    public virtual void RegisterIgnition(Ignition ignition)
    {
      _ignition = ignition;
    }

    public virtual void RegisterGearbox(Gearbox gearbox)
    {
      _gearbox = gearbox;
    }

    public virtual void RegisterAccelerator(Accelerator accelerator)
    {
      _accelerator = accelerator;
    }

    public virtual void RegisterBrake(Brake brake)
    {
      _brake = brake;
    }


    // Methods that handle object interactions...

    public virtual void IgnitionTurnedOn()
    {
      _gearbox.Enable();
      _accelerator.Enable();
      _brake.Enable();
    }

    public virtual void IgnitionTurnedOff()
    {
      _gearbox.Disable();
      _accelerator.Disable();
      _brake.Disable();
    }

    public virtual void GearboxEnabled() => WriteLine("EMS now controlling the gearbox");

    public virtual void GearboxDisabled()
    {
      WriteLine("EMS no longer controlling the gearbox");
    }

    public virtual void GearChanged()
    {
      WriteLine("EMS disengaging revs while gear changing");
    }

    public virtual void AcceleratorEnabled()
    {
      WriteLine("EMS now controlling the accelerator");
    }

    public virtual void AcceleratorDisabled()
    {
      WriteLine("EMS no longer controlling the accelerator");
    }

    public virtual void AcceleratorPressed()
    {
      _brake.Disable();
      while (currentSpeed < _accelerator.Speed)
      {
        currentSpeed++;
        WriteLine("Speed currentlt " + currentSpeed);

        // Set gear according to speed
        if (currentSpeed <= 10)
        {
          _gearbox.Gear = Gear.First;

        }
        else if (currentSpeed <= 20)
        {
          _gearbox.Gear = Gear.Second;

        }
        else if (currentSpeed <= 30)
        {
          _gearbox.Gear = Gear.Third;

        }
        else if (currentSpeed <= 50)
        {
          _gearbox.Gear = Gear.Fourth;

        }
        else
        {
          _gearbox.Gear = Gear.Fifth;
        }
      }
      _brake.Enable();
    }

    public virtual void BrakeEnabled()
    {
      WriteLine("EMS now controlling the brake");
    }

    public virtual void BrakeDisabled()
    {
      WriteLine("EMS no longer controlling the brake");
    }

    public virtual void BrakePressed()
    {
      _accelerator.Disable();
      currentSpeed = 0;
    }

    public virtual void BrakeReleased()
    {
      _gearbox.Gear = Gear.First;
      _accelerator.Enable();
    }
  }
}
