﻿using RxStateMachine.Condiguration;
using RxStateMachine.States;
using RxStateMachine.Transitions;
using RxStateMachine.Triggers;
using System.Collections.Concurrent;
using System.ComponentModel;
using System.Windows.Threading;

namespace RxStateMachine.StateMachine;

/// <inheritdoc cref="IReactiveStateMachine" />
/// <summary>
/// TODO: Add error handling to all observables !
/// TODO: All events should be fired on the Dispatcher !
/// </summary>
/// <typeparam name="T"></typeparam>
public class ReactiveStateMachine<T> : IReactiveStateMachine1<T>
{
  #region private fields

  private BlockingCollection<Action> _queue;

  private readonly Dictionary<T, State<T>> _states = new();

  private bool _running;

  internal Dispatcher CurrentDispatcher { get; private set; }

  private readonly BlockingCollection<Action> _configurationQueue = new();

  #endregion

  #region ctor

  public ReactiveStateMachine(string rsmName, T startState)
  {
    Name = rsmName;
    StartState = startState;

    if(Thread.CurrentThread.GetApartmentState() == ApartmentState.STA)
    {
      CurrentDispatcher = Dispatcher.CurrentDispatcher;
    }
  }

  #endregion

  #region public properties

  #region CurrentState

  private T _currentState;

  /// <summary>
  /// Gets or sets the CurrentState property. This observable property 
  /// indicates ....
  /// </summary>
  public T CurrentState
  {
    get => _currentState;
    private set
    {
      if(_currentState.Equals(value)) return;
      _currentState = value;
      RaisePropertyChanged("CurrentState");
    }
  }

  #endregion

  #region StartState

  private T _startState;

  /// <summary>
  /// Gets or sets the StartState property. This observable property 
  /// indicates ....
  /// </summary>
  public T StartState
  {
    get => _startState;
    set
    {
      if(_currentState.Equals(value)) return;
      _startState = value;
      RaisePropertyChanged("StartState");
    }
  }

  #endregion

  #region AssociatedVisualStateManager

  public ReactiveVisualStateManager AssociatedVisualStateManager
  {
    get;
    set;
  }

  #endregion

  #region Name

  public string Name { get; private set; }

  #endregion

  #endregion

  #region public events

  #region State Changed

  public event EventHandler<StateChangedEventArgs<T>> StateChanged;

  private void RaiseStateChanged(StateChangedEventArgs<T> e)
  {
    var handler = StateChanged;

    if(handler == null) return;

    Action action = () => handler(this, e);

    if(CurrentDispatcher != null)
      CurrentDispatcher.Invoke(action, null);
    else
      action();
  }

  private void RaiseStateChanged(T fromState, T toState)
  {
    RaiseStateChanged(new StateChangedEventArgs<T>(fromState, toState));
  }

  #endregion

  #region State Machine Started

  public event EventHandler StateMachineStarted;

  private void RaiseStateMachineStarted()
  {
    var handler = StateMachineStarted;

    if(handler == null) return;

    Action action = () => handler(this, EventArgs.Empty);

    if(CurrentDispatcher != null)
      CurrentDispatcher.Invoke(action, null);
    else
      action();
  }

  #endregion

  #region State Machine Stopped

  public event EventHandler StateMachineStopped;

  private void RaiseStateMachineStopped()
  {
    var handler = StateMachineStopped;

    if(handler == null) return;

    Action action = () => handler(this, EventArgs.Empty);

    if(CurrentDispatcher != null)
      CurrentDispatcher.Invoke(action, null);
    else
      action();
  }

  #endregion

  #region State Machine Exception

  public event EventHandler<StateMachineExceptionEventArgs> StateMachineException;

  internal void RaiseStateMachineException(Exception e)
  {
    RaiseStateMachineException(new StateMachineExceptionEventArgs(e));
  }

  private void RaiseStateMachineException(StateMachineExceptionEventArgs e)
  {
    var handler = StateMachineException;

    if(handler == null) return;

    Action action = () => handler(this, e);

    if(CurrentDispatcher != null)
      CurrentDispatcher.Invoke(action, null);
    else
      action();
  }

  #endregion

  #endregion

  #region public methods

  #region State Machine Management

  public void Start()
  {
    if(_running)
      throw new InvalidOperationException("State machine is already running");
    _running = true;


    //consume all actions from the configuration queue
    Action configurationAction;

    while(_configurationQueue.TryTake(out configurationAction))
      configurationAction();


    _queue = new BlockingCollection<Action>();

    Task.Factory.StartNew(() =>
    {
      foreach(Action transition in _queue.GetConsumingEnumerable())
      {
        transition();
      }
    });

    _queue.Add(StartStateMachineInternal);
  }

  public void Stop()
  {
    if(!_running)
      return;

    _running = false;

    _queue.CompleteAdding();

    while(!_queue.IsCompleted)
      Thread.Sleep(10);

    RaiseStateMachineStopped();
  }

  public void Resume()
  {

  }

  public void Pause()
  {

  }

  #endregion

  #region Configuration API

  #region Entry Actions

  /// <summary>
  /// Adds an entry action to the given state, which will be executed whenever the state is entered
  /// </summary>
  /// <param name="enteredState"></param>
  /// <param name="entryAction"></param>
  public void AddEntryAction(T enteredState, Action entryAction)
  {
    if(entryAction == null)
      throw new ArgumentNullException("entryAction");

    AddEntryAction(enteredState, entryAction, null);
  }

  /// <summary>
  /// Adds an entry action to the given state, which will be executed whenever the state is entered and the given condition evaluates to true
  /// </summary>
  /// <param name="enteredState"></param>
  /// <param name="entryAction"></param>
  /// <param name="condition"></param>
  public void AddEntryAction(T enteredState, Action entryAction, Func<bool> condition)
  {
    if(entryAction == null)
      throw new ArgumentNullException("entryAction");

    var state = GetState(enteredState);
    state.AddEntryAction(entryAction, condition);
  }

  /// <summary>
  /// Adds an entry action to the given state, which will be executed whenever the state is entered from the given previous state
  /// </summary>
  /// <param name="enteredState"></param>
  /// <param name="fromState"></param>
  /// <param name="entryAction"></param>
  public void AddEntryAction(T enteredState, T fromState, Action entryAction)
  {
    if(entryAction == null)
      throw new ArgumentNullException("entryAction");

    AddEntryAction(enteredState, fromState, entryAction, null);
  }

  /// <summary>
  /// Adds an entry action to the given state, which will be executed whenever the state is entered from the given previous state and the given condition evaluates to true
  /// </summary>
  /// <param name="enteredState"></param>
  /// <param name="fromState"></param>
  /// <param name="entryAction"></param>
  /// <param name="condition"></param>
  public void AddEntryAction(T enteredState, T fromState, Action entryAction, Func<bool> condition)
  {
    if(entryAction == null)
      throw new ArgumentNullException("entryAction");

    if(enteredState.Equals(fromState))
      throw new InvalidOperationException("entry actions are not allowed/executed for internal transitions, i.e. transitions that start and end in the same state");

    var state = GetState(enteredState);
    state.AddEntryAction(fromState, entryAction, condition);
  }

  #endregion

  #region Exit Actions

  /// <summary>
  /// Adds an exit action to the given state, which will be executed whenever the state is exited
  /// </summary>
  /// <param name="currentState"></param>
  /// <param name="exitAction"></param>
  public void AddExitAction(T currentState, Action exitAction)
  {
    if(exitAction == null)
      throw new ArgumentNullException("exitAction");

    AddExitAction(currentState, exitAction, null);
  }

  /// <summary>
  /// Adds an exit action to the given state, which will be executed whenever the state is exited and the given condition evaluates to true
  /// </summary>
  /// <param name="currentState"></param>
  /// <param name="exitAction"></param>
  /// <param name="condition"></param>
  public void AddExitAction(T currentState, Action exitAction, Func<bool> condition)
  {
    if(exitAction == null)
      throw new ArgumentNullException("exitAction");

    var state = GetState(currentState);
    state.AddExitAction(exitAction, condition);
  }

  /// <summary>
  /// Adds an exit action to the given state, which will be executed whenever the state is exited to the given next state
  /// </summary>
  /// <param name="currentState"></param>
  /// <param name="toState"></param>
  /// <param name="exitAction"></param>
  public void AddExitAction(T currentState, T toState, Action exitAction)
  {
    if(exitAction == null)
      throw new ArgumentNullException("exitAction");

    AddExitAction(currentState, toState, exitAction, null);
  }

  /// <summary>
  /// Adds an exit action to the given state, which will be executed whenever the state is exited to the given next state and the given condition evaluates to true
  /// </summary>
  /// <param name="currentState"></param>
  /// <param name="toState"></param>
  /// <param name="exitAction"></param>
  /// <param name="condition"></param>
  public void AddExitAction(T currentState, T toState, Action exitAction, Func<bool> condition)
  {
    if(exitAction == null)
      throw new ArgumentNullException("exitAction");

    if(currentState.Equals(toState))
      throw new InvalidOperationException("exit actions are not allowed/executed for internal transitions, i.e. transitions that start and end in the same state");

    var state = GetState(currentState);
    state.AddExitAction(toState, exitAction, condition);
  }

  #endregion

  #region Triggered Transitions

  public void AddTransition<TTrigger>(
    T fromState, 
    T toState, 
    IObservable<TTrigger> trigger) where TTrigger : class
  {
    AddTransition(fromState, toState, trigger, null, null);
  }

  public void AddTransition<TTrigger>(
    T fromState, 
    T toState, 
    IObservable<TTrigger> trigger, 
    Func<TTrigger, bool> condition) where TTrigger : class
  {
    AddTransition(fromState, toState, trigger, condition, null);
  }

  public void AddTransition<TTrigger>(
    T fromState,
    T toState,
    IObservable<TTrigger> trigger,
    Action<TTrigger> transitionAction) where TTrigger : class
  {
    AddTransition(fromState, toState, trigger, null, transitionAction);
  }

  public void AddTransition<TTrigger>(
    T fromState, 
    T toState, 
    IObservable<TTrigger> trigger,
    Func<TTrigger, bool> condition, 
    Action<TTrigger> transitionAction) where TTrigger : class
  {
    AddTransition(fromState, toState, new Trigger<TTrigger>(trigger), condition, transitionAction);
  }

  public void AddTransition<TTrigger>(
    T fromState, 
    T toState, 
    Trigger<TTrigger> trigger) where TTrigger : class
  {
    AddTransition(fromState, toState, trigger, null, null);
  }

  public void AddTransition<TTrigger>(
    T fromState, 
    T toState, 
    Trigger<TTrigger> trigger, 
    Func<TTrigger, bool> condition) where TTrigger : class
  {
    AddTransition(fromState, toState, trigger, condition, null);
  }

  public void AddTransition<TTrigger>(
    T fromState, 
    T toState, 
    Trigger<TTrigger> trigger, 
    Action<TTrigger> transitionAction) where TTrigger : class
  {
    AddTransition(fromState, toState, trigger, null, transitionAction);
  }

  public void AddTransition<TTrigger>(
    T fromState, 
    T toState, 
    Trigger<TTrigger> trigger, 
    Func<TTrigger, bool> condition, 
    Action<TTrigger> transitionAction) where TTrigger : class
  {
    var stateObject_ = GetState(fromState);
    var transition_ = new TriggeredTransition<T, TTrigger>(fromState, toState, trigger, transitionAction, condition);
    stateObject_.AddTriggeredTransition(transition_);
  }

  public TriggeredTransitionConfiguration<T, TTrigger> AddTransition<TTrigger>(IObservable<TTrigger> trigger) where TTrigger : class
  {
    return AddTransition(new Trigger<TTrigger>(trigger));
  }

  public TriggeredTransitionConfiguration<T, TTrigger> AddTransition<TTrigger>(Trigger<TTrigger> trigger) where TTrigger : class
  {
    var config = new TriggeredTransitionConfiguration<T, TTrigger>(trigger);

    _configurationQueue.Add(() =>
    {
      if(!config.IsFromStateSet || !config.IsToStateSet)
      {
        RaiseStateMachineException(new StateMachineConfigurationException("Transition configuration is underspecified"));
        return;
      }

      AddTransition(config.FromState, config.ToState, config.Trigger, config.Condition, config.TransitionAction);
    });

    return config;
  }

  #endregion

  #region Timed Transitions

  public void AddTimedTransition(T fromState, T toState, TimeSpan after)
  {
    AddTimedTransition(fromState, toState, after, null, null);
  }

  public void AddTimedTransition(T fromState, T toState, TimeSpan after, Func<bool> condition)
  {
    AddTimedTransition(fromState, toState, after, condition, null);
  }

  /// <summary>
  /// Adds a transition from <para>fromState</para> to <para>toState</para>, which will be made when the given time span has elapsed. The given transition action is executed during the transition
  /// </summary>
  /// <param name="fromState"></param>
  /// <param name="toState"></param>
  /// <param name="after"></param>
  /// <param name="transitionAction"></param>
  public void AddTimedTransition(T fromState, T toState, TimeSpan after, Action transitionAction)
  {
    AddTimedTransition(fromState, toState, after, null, transitionAction);
  }

  public void AddTimedTransition(T fromState, T toState, TimeSpan after, Func<bool>? condition, Action? transitionAction)
  {
    var stateObject_ = GetState(fromState);

    Func<object, bool> realCondition_ = null;
    if(condition != null)
      realCondition_ = o => condition();

    Action<object> realAction_ = null;
    if(transitionAction != null)
      realAction_ = o => transitionAction();


    stateObject_.AddTimedTransition(new TimedTransition<T, object>(fromState, toState, after, realCondition_, realAction_));
  }

  public TimedTransitionConfiguration<T> AddTimedTransition(TimeSpan after)
  {
    var config = new TimedTransitionConfiguration<T>(after);

    _configurationQueue.Add(() =>
    {
      if(!config.IsFromStateSet || !config.IsToStateSet)
      {
        RaiseStateMachineException(new StateMachineConfigurationException("Transition configuration is underspecified"));
        return;
      }

      AddTimedTransition(config.FromState, config.ToState, config.After, config.Condition, config.TransitionAction);
    });

    return config;
  }

  #endregion

  #region Automatic Transitions

  public void AddAutomaticTransition(T fromState, T toState)
  {
    AddAutomaticTransition(fromState, toState, null, null, false);
  }

  public void AddAutomaticTransition(T fromState, T toState, bool oneTime)
  {
    AddAutomaticTransition(fromState, toState, null, null, oneTime);
  }

  public void AddAutomaticTransition(T fromState, T toState, Func<bool> condition)
  {
    AddAutomaticTransition(fromState, toState, condition, null, false);
  }

  public void AddAutomaticTransition(T fromState, T toState, Func<bool> condition, bool oneTime)
  {
    AddAutomaticTransition(fromState, toState, condition, null, oneTime);
  }

  /// <summary>
  /// Adds an automatic state transition from <para>fromState</para> to <para>toState</para>. This transition is initiated as soon as <para>fromState</para> is active.
  /// </summary>
  /// <param name="fromState"></param>
  /// <param name="toState"></param>
  /// <param name="transitionAction"></param>
  public void AddAutomaticTransition(T fromState, T toState, Action transitionAction)
  {
    AddAutomaticTransition(fromState, toState, null, transitionAction, false);
  }

  /// <summary>
  /// Adds an automatic state transition from <para>fromState</para> to <para>toState</para>. This transition is initiated as soon as <para>fromState</para> is active.
  /// </summary>
  /// <param name="fromState"></param>
  /// <param name="toState"></param>
  /// <param name="transitionAction"></param>
  /// <param name="oneTime"></param>
  public void AddAutomaticTransition(T fromState, T toState, Action transitionAction, bool oneTime)
  {
    AddAutomaticTransition(fromState, toState, null, transitionAction, oneTime);
  }

  public void AddAutomaticTransition(T fromState, T toState, Func<bool> condition, Action transitionAction)
  {
    AddAutomaticTransition(fromState, toState, condition, transitionAction, false);
  }

  public void AddAutomaticTransition(T fromState, T toState, Func<bool>? condition, Action? transitionAction, bool oneTime)
  {
    var stateObject = GetState(fromState);

    Func<object, bool> realCondition = null;
    if(condition != null)
      realCondition = o => condition();

    Action<object> realAction = null;
    if(transitionAction != null)
      realAction = o => transitionAction();

    stateObject.AddAutomaticTransition(new Transition<T, object>(fromState, toState, realCondition, realAction, oneTime));
  }

  public AutomaticTransitionConfiguration<T> AddAutomaticTransition()
  {
    var config = new AutomaticTransitionConfiguration<T>();

    _configurationQueue.Add(() =>
    {
      if(!config.IsFromStateSet || !config.IsToStateSet)
      {
        RaiseStateMachineException(new StateMachineConfigurationException("Transition configuration is underspecified"));
        return;
      }

      AddAutomaticTransition(config.FromState, config.ToState, config.Condition, config.TransitionAction, config.OneTime);
    });

    return config;
  }

  #endregion

  #region State Toggles

  /// <summary>
  /// Adds a state toggle between <para>stateOne</para> and <para>stateTwo</para>, which will be triggered by the given trigger. The given transition actions are executed during the respective state transition.
  /// </summary>
  /// <typeparam name="TTrigger"></typeparam>
  /// <param name="stateOne"></param>
  /// <param name="stateTwo"></param>
  /// <param name="trigger"></param>
  /// <param name="transitionActionOne"></param>
  /// <param name="transitionActionTwo"></param>
  public void AddStateToggle<TTrigger>(T stateOne, T stateTwo, IObservable<TTrigger> trigger, Action<TTrigger> transitionActionOne, Action<TTrigger> transitionActionTwo) where TTrigger : class
  {
    AddTransition(stateOne, stateTwo, trigger, transitionActionOne);
    AddTransition(stateTwo, stateOne, trigger, transitionActionTwo);
  }

  #endregion

  #endregion

  #endregion

  #region private methods

  private State<T> GetState(T state)
  {
    State<T> stateObject;
    if(!_states.TryGetValue(state, out stateObject))
    {
      stateObject = new State<T>(state, this);
      _states.Add(state, stateObject);
    }
    return stateObject;
  }

  private void StartStateMachineInternal()
  {
    var state = GetState(StartState);

    if(AssociatedVisualStateManager != null)
      AssociatedVisualStateManager.TransitionState(Name, null, StartState.ToString());


    state.Enter(StartState);

    CurrentState = StartState;

    if(!state.TryAutomaticTransition())
      state.ResumeTransitions();

    RaiseStateMachineStarted();
  }

  #endregion

  #region internal methods

  object _lastTrigger = null;

  protected ReactiveStateMachine()
  {
    
  }

  internal void TransitionStateInternal<TTrigger>(T fromState, T toState, TTrigger trigger, Action<TTrigger>? transitionAction)
  {
    //we have to check, that the same event may only come in once. this solves an issue with the tracking mechanism
    if(trigger is EventArgs)
    {
      if(trigger.Equals(_lastTrigger))
      {
        _lastTrigger = trigger;
        return;
      }
      _lastTrigger = trigger;
    }

    TransitionOverride(fromState, toState, trigger);

    if(!CurrentState.Equals(fromState))
      return;

    var isInternalTransition = fromState.Equals(toState);

    Task<bool> vsmTransition = null;

    if(!isInternalTransition && AssociatedVisualStateManager != null)
    {
      vsmTransition = AssociatedVisualStateManager.TransitionState(Name, fromState.ToString(), toState.ToString());
    }

    var currentState = GetState(fromState);
    var futureState = GetState(toState);

    //exit the current state
    if(!isInternalTransition)
    {
      currentState.IgnoreTransitions();
      currentState.Exit(toState);
    }

    //call the transition action
    if(transitionAction != null)
    {
      Action safeAction = () =>
      {
        try
        {
          transitionAction(trigger);
        }
        catch(Exception e)
        {
          RaiseStateMachineException(e);
        }
      };

      if(CurrentDispatcher != null)
      {
        CurrentDispatcher.Invoke(safeAction, null);
      }
      else
        safeAction();
    }

    //enter the next state
    if(!isInternalTransition)
    {
      futureState.Enter(fromState);
      futureState.ResumeTransitions();

      CurrentState = toState;

      RaiseStateChanged(fromState, toState);
    }

    //we can only make automatic transitions if we entered the current state from somewhere else
    if(!isInternalTransition)
    {
      if(vsmTransition == null || vsmTransition.IsCompleted)
        futureState.TryAutomaticTransition();
      else
        vsmTransition.ContinueWith(result => futureState.TryAutomaticTransition());
    }
  }

  internal void EnqueueTransition(Action transition)
  {
    _queue.Add(transition);
  }

  #endregion

  #region protected methods

  protected virtual void TransitionOverride<T, TTrigger>(T fromState, T toState, TTrigger trigger)
  {

  }

  #endregion

  #region INotifyPropertyChanged Members

  public event PropertyChangedEventHandler? PropertyChanged;

  private void RaisePropertyChanged(string name)
  {
    PropertyChangedEventHandler handler = PropertyChanged;
    if(handler != null) handler(this, new PropertyChangedEventArgs(name));
  }

  #endregion

  #region IDisposable Members
  //TODO: proper IDisposable implementation
  public void Dispose()
  {
    throw new NotImplementedException();
  }

  #endregion
}