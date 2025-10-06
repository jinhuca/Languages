using System;

namespace D18_Memento
{

  [Serializable]
  public class Speedometer2
  {
    private int currentSpeed;
    private int previousSpeed;

    public Speedometer2()
    {
      currentSpeed = 0;
      previousSpeed = 0;
    }

    public virtual int CurrentSpeed
    {
      set
      {
        previousSpeed = currentSpeed;
        currentSpeed = value;
      }
      get => currentSpeed;
    }

    // Only defined to help testing...
    public virtual int PreviousSpeed
    {
      get => previousSpeed;
      set => previousSpeed = value;
    }
  }
}
