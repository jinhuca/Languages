using RxStateMachine.StateMachine;
using RxStateMachine.Triggers;
using System.Diagnostics;
using System.Reactive.Linq;
using System.Windows;
using System.Windows.Input;
using Module.Infrastructure;

namespace WpfApp1;

public partial class MainWindow : Window
{
  private ReactiveStateMachine<ConsoleStateId> _sm1;

  private ReactiveStateMachine<VisibilityStates> _stateMachine;

  private IObservable<MouseEventArgs> _mouseDownTrigger;

  private Trigger<MouseEventArgs> _mouseUpTrigger;

  public MainWindow()
  {
    InitializeComponent();
    Loaded += MainWindow_Loaded;
  }

  void MainWindow_Loaded(object sender, RoutedEventArgs args)
  {
    #region (1) Define state machine
    
    _stateMachine = new ReactiveStateMachine<VisibilityStates>(
      rsmName: "VisibilityStates",
      startState: VisibilityStates.Collapsed);
    
    #endregion

    #region (2) Define triggers

    _mouseDownTrigger = Observable
      .FromEventPattern<MouseEventArgs>(target: this, eventName: nameof(MouseDown))
      .Select(selector: evt => evt.EventArgs);

    _mouseUpTrigger = new Trigger<MouseEventArgs>(source: Observable
      .FromEventPattern<MouseEventArgs>(target: this, eventName: nameof(MouseUp))
      .Select(selector: evt => evt.EventArgs));

    #endregion

    #region (3) Add Triggers

    _stateMachine.AddTransition(
      fromState: VisibilityStates.Collapsed,
      toState: VisibilityStates.FadingIn,
      trigger: _mouseDownTrigger,
      transitionAction: e => Debug.WriteLine(message: "MouseDown"));

    _stateMachine.AddTransition(
      fromState: VisibilityStates.FadingIn,
      toState: VisibilityStates.Visible,
      trigger: _mouseUpTrigger,
      transitionAction: e => Debug.WriteLine(message: "MouseUp"));

    _stateMachine.AddTransition(
      fromState: VisibilityStates.Visible,
      toState: VisibilityStates.Collapsed,
      trigger: _mouseDownTrigger,
      transitionAction: e => Debug.WriteLine(message: "MouseDown"));

    #region (4) Add entry and exit actions

    _stateMachine.AddEntryAction(
      enteredState: VisibilityStates.Visible,
      entryAction: () => Debug.WriteLine(message: "Entering Visible State"));

    _stateMachine.AddExitAction(
      currentState: VisibilityStates.Visible,
      exitAction: () => Debug.WriteLine(message: "Exiting Visible State"));

    #endregion

    #endregion

    #region (5) Start state machine

    _stateMachine.Start();
    
    #endregion
  }

  void cmDemo()
  {
    _sm1 = new ReactiveStateMachine<ConsoleStateId>("ConsoleSM", ConsoleStateId.Unknown);

  }
}