namespace RxStateMachine.Condiguration;

public class TimedTransitionConfiguration<T> : TransitionConfiguration<T>
{
  public TimedTransitionConfiguration(TimeSpan after)
  {
    After = after;
  }

  internal TimeSpan After { get; private set; }
}