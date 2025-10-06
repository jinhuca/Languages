using System;

namespace D20_State
{
  public class HourSetupState : ClockSetupState
  {
    private ClockSetup clockSetup;
    private int hour;

    public HourSetupState(ClockSetup clockSetup)
    {
      this.clockSetup = clockSetup;
      hour = DateTime.Now.Hour;
    }

    public virtual void PreviousValue()
    {
      if (hour > 0)
      {
        hour--;
      }
    }

    public virtual void NextValue()
    {
      if (hour < 23)
      {
        hour++;
      }
    }

    public virtual void SelectValue()
    {
      Console.WriteLine("Hour set to " + hour);
      clockSetup.State = clockSetup.MinuteSetupState;
    }

    public virtual string Instructions
    {
      get
      {
        return "Please set the hour...";
      }
    }

    public virtual int SelectedValue
    {
      get
      {
        return hour;
      }
    }

  }
}
