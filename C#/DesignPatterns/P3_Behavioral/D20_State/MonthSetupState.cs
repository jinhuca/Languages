using System;

namespace D20_State
{
  public class MonthSetupState : ClockSetupState
  {
    private ClockSetup clockSetup;
    private int month;

    public MonthSetupState(ClockSetup clockSetup)
    {
      this.clockSetup = clockSetup;
      month = DateTime.Now.Month;
    }

    public virtual void PreviousValue()
    {
      if (month > 0)
      {
        month--;
      }
    }

    public virtual void NextValue()
    {
      if (month < 11)
      {
        month++;
      }
    }

    public virtual void SelectValue()
    {
      Console.WriteLine("Month set to " + month);
      clockSetup.State = clockSetup.DaySetupState;
    }

    public virtual string Instructions
    {
      get
      {
        return "Please set the month...";
      }
    }

    public virtual int SelectedValue
    {
      get
      {
        return month;
      }
    }

  }
}
