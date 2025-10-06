﻿namespace RxStateMachine;

public class StateMachineExceptionEventArgs : EventArgs
{
  public StateMachineExceptionEventArgs(Exception e)
  {
    Exception = e;
  }

  public Exception Exception { get; private set; }
}