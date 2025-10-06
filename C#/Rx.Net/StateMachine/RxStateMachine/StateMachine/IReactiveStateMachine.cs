namespace RxStateMachine.StateMachine;

public interface IReactiveStateMachine
{
  ReactiveVisualStateManager AssociatedVisualStateManager { get; set; }
}