using System.ComponentModel;
using RxStateMachine.Transitions;

namespace RxStateMachine.States;

public interface IState<T> : INotifyPropertyChanged
{
  T StateRepresentation { get; }

  void AddAutomaticTransition(Transition<T, object> transition);
  
  void AddEntryAction(Action entryAction, Func<bool> condition);
  void AddEntryAction(T fromState, Action entryAction, Func<bool> condition);
  
  void AddExitAction(Action exitAction, Func<bool> condition);
  void AddExitAction(T toState, Action exitAction, Func<bool> condition);
  
  void AddTimedTransition(TimedTransition<T, object> timedTransition);
  void AddTriggeredTransition<TTrigger>(TriggeredTransition<T, TTrigger> transition) where TTrigger : class;
  
  void Enter(T fromState);
  void Exit(T toState);
  
  IEnumerable<Action> GetValidExitActions(T toState);
  void IgnoreTransitions();
  void ResumeTransitions();
  bool TryAutomaticTransition();
}