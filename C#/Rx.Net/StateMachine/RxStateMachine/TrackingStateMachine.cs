﻿using RxStateMachine.StateMachine;

namespace RxStateMachine;

public class TrackingStateMachine<T> : ReactiveStateMachine<T>
{
  protected IInputPointTracker InputTracker { get; private set; }

  public TrackingStateMachine(String name, T startState, IInputPointTracker inputTracker) : base(name, startState)
  {
    if(inputTracker == null)
      throw new ArgumentNullException("inputTracker");

    InputTracker = inputTracker;
  }

  protected override void TransitionOverride<T, TTrigger>(T fromState, T toState, TTrigger trigger)
  {
    if(trigger is EventArgs)
      InputTracker.Track(trigger as EventArgs);
  }

}