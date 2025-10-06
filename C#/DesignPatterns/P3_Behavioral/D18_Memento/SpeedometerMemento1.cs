namespace D18_Memento
{
  public class SpeedometerMemento1
  {
    private Speedometer1 speedometer;

    private int copyOfCurrentSpeed;
    private int copyOfPreviousSpeed;

    public SpeedometerMemento1(Speedometer1 speedometer)
    {
      this.speedometer = speedometer;
      copyOfCurrentSpeed = speedometer.CurrentSpeed;
      copyOfPreviousSpeed = speedometer.previousSpeed;
    }

    public virtual void RestoreState()
    {
      speedometer.CurrentSpeed = copyOfCurrentSpeed;
      speedometer.previousSpeed = copyOfPreviousSpeed;
    }
  }
}
