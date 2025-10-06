using System;

namespace D19_Observer
{
  public class Speedometer
  {
    public event EventHandler ValueChanged;
    private int currentSpeed;

    public Speedometer()
    {
      currentSpeed = 0;
    }

    public virtual int CurrentSpeed
    {
      set
      {
        currentSpeed = value;

        // Tell all observers so they know value has changed...
        OnValueChanged();
      }
      get
      {
        return currentSpeed;
      }
    }

    protected void OnValueChanged()
    {
      ValueChanged?.Invoke(this, EventArgs.Empty);
    }
  }
}
