using System;

namespace D20_State
{
  public class YearSetupState : ClockSetupState
  {
    private ClockSetup clockSetup;
    private int year;

    public YearSetupState(ClockSetup clockSetup)
    {
      this.clockSetup = clockSetup;
      year = DateTime.Now.Year;
    }

    public virtual void PreviousValue()
    {
      year--;
    }

    public virtual void NextValue()
    {
      year++;
    }

    public virtual void SelectValue()
    {
      Console.WriteLine("Year set to " + year);
      clockSetup.State = clockSetup.MonthSetupState;
    }

    public virtual string Instructions
    {
      get
      {
        return "Please set the year...";
      }
    }

    public virtual int SelectedValue
    {
      get
      {
        return year;
      }
    }

  }
}
