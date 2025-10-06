using RxStateMachine.Condiguration;
using RxStateMachine.Triggers;
using System.ComponentModel;

namespace RxStateMachine.StateMachine
{
  public interface IReactiveStateMachine1<T> : IDisposable, INotifyPropertyChanged
  {
    ReactiveVisualStateManager AssociatedVisualStateManager { get; set; }
    T CurrentState { get; }
    string Name { get; }
    T StartState { get; set; }

    event PropertyChangedEventHandler? PropertyChanged;
    event EventHandler<StateChangedEventArgs<T>> StateChanged;
    event EventHandler<StateMachineExceptionEventArgs> StateMachineException;
    event EventHandler StateMachineStarted;
    event EventHandler StateMachineStopped;

    AutomaticTransitionConfiguration<T> AddAutomaticTransition();
    void AddAutomaticTransition(T fromState, T toState);
    void AddAutomaticTransition(T fromState, T toState, Action transitionAction);
    void AddAutomaticTransition(T fromState, T toState, Action transitionAction, bool oneTime);
    void AddAutomaticTransition(T fromState, T toState, bool oneTime);
    void AddAutomaticTransition(T fromState, T toState, Func<bool> condition);
    void AddAutomaticTransition(T fromState, T toState, Func<bool> condition, Action transitionAction);
    void AddAutomaticTransition(T fromState, T toState, Func<bool> condition, bool oneTime);
    void AddAutomaticTransition(T fromState, T toState, Func<bool>? condition, Action? transitionAction, bool oneTime);
    void AddEntryAction(T enteredState, Action entryAction);
    void AddEntryAction(T enteredState, Action entryAction, Func<bool> condition);
    void AddEntryAction(T enteredState, T fromState, Action entryAction);
    void AddEntryAction(T enteredState, T fromState, Action entryAction, Func<bool> condition);
    void AddExitAction(T currentState, Action exitAction);
    void AddExitAction(T currentState, Action exitAction, Func<bool> condition);
    void AddExitAction(T currentState, T toState, Action exitAction);
    void AddExitAction(T currentState, T toState, Action exitAction, Func<bool> condition);
    void AddStateToggle<TTrigger>(T stateOne, T stateTwo, IObservable<TTrigger> trigger, Action<TTrigger> transitionActionOne, Action<TTrigger> transitionActionTwo) where TTrigger : class;
    void AddTimedTransition(T fromState, T toState, TimeSpan after);
    void AddTimedTransition(T fromState, T toState, TimeSpan after, Action transitionAction);
    void AddTimedTransition(T fromState, T toState, TimeSpan after, Func<bool> condition);
    void AddTimedTransition(T fromState, T toState, TimeSpan after, Func<bool>? condition, Action? transitionAction);
    TimedTransitionConfiguration<T> AddTimedTransition(TimeSpan after);
    TriggeredTransitionConfiguration<T, TTrigger> AddTransition<TTrigger>(IObservable<TTrigger> trigger) where TTrigger : class;
    void AddTransition<TTrigger>(T fromState, T toState, IObservable<TTrigger> trigger) where TTrigger : class;
    void AddTransition<TTrigger>(T fromState, T toState, IObservable<TTrigger> trigger, Action<TTrigger> transitionAction) where TTrigger : class;
    void AddTransition<TTrigger>(T fromState, T toState, IObservable<TTrigger> trigger, Func<TTrigger, bool> condition) where TTrigger : class;
    void AddTransition<TTrigger>(T fromState, T toState, IObservable<TTrigger> trigger, Func<TTrigger, bool> condition, Action<TTrigger> transitionAction) where TTrigger : class;
    void AddTransition<TTrigger>(T fromState, T toState, Trigger<TTrigger> trigger) where TTrigger : class;
    void AddTransition<TTrigger>(T fromState, T toState, Trigger<TTrigger> trigger, Action<TTrigger> transitionAction) where TTrigger : class;
    void AddTransition<TTrigger>(T fromState, T toState, Trigger<TTrigger> trigger, Func<TTrigger, bool> condition) where TTrigger : class;
    void AddTransition<TTrigger>(T fromState, T toState, Trigger<TTrigger> trigger, Func<TTrigger, bool> condition, Action<TTrigger> transitionAction) where TTrigger : class;
    TriggeredTransitionConfiguration<T, TTrigger> AddTransition<TTrigger>(Trigger<TTrigger> trigger) where TTrigger : class;
    void Dispose();
    void Pause();
    void Resume();
    void Start();
    void Stop();
  }
}