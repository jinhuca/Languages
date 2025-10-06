namespace D20_State
{
  public class Program
  {
    public static void Main(string[] args)
    {
      ClockSetup clockSetup = new ClockSetup();

      // Setup starts in 'year' state
      clockSetup.RotateKnobRight();
      clockSetup.PushKnob(); // year should be 1 on from current

      // Setup should now be in 'month' state
      clockSetup.RotateKnobRight();
      clockSetup.RotateKnobRight();
      clockSetup.PushKnob(); // month should be 2 on from current

      // Setup should now be in 'day' state
      clockSetup.RotateKnobRight();
      clockSetup.RotateKnobRight();
      clockSetup.RotateKnobRight();
      clockSetup.PushKnob(); // day should be 3 on from current

      // Setup should now be in 'hour' state
      clockSetup.RotateKnobLeft();
      clockSetup.RotateKnobLeft();
      clockSetup.PushKnob(); // hour should be 2 less than current

      // Setup should now be in 'minute' state
      clockSetup.RotateKnobRight();
      clockSetup.PushKnob(); // minute should be 1 on than current

      // Setup should now be in 'finished' state
      clockSetup.PushKnob(); // to display selected date
    }
  }
}
