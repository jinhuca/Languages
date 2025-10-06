// See https://aka.ms/new-console-template for more information

using System.ComponentModel;
using System.Reactive.Linq;
using System.Runtime.CompilerServices;
using Module.Infrastructure;
using RxStateMachine.StateMachine;
using RxStateMachine.States;
using RxStateMachine.Transitions;
using RxStateMachine.Triggers;

public class Program
{
  public static void Main()
  {
    PropertyChangedDemo1();
    StateChangedDemo1();
  }

  private static void PropertyChangedDemo1()
  {
    var Dave = new Person();
    Dave
      .OnAnyPropertyChanges()
      .Subscribe(v => Console.WriteLine($"Person's name = {v.Name}, Age ={v.Age}"));

    Dave.Name = "Dave";
    Dave.Age = 25;

    var John = new Person
    {
      Name = "John",
      Age = 25
    };
    John
      .OnPropertyChanges(x => x.Name).Subscribe(x => Console.WriteLine($"Person's Name changes to {x}"));
    John.Name = "Johnson";
    John.Age = 34;

    Console.ReadLine();
  }

  private static void StateChangedDemo1()
  {
    //var state1_ = new ConsoleState(ConsoleStateId.Idle) { Age = 10 };
    //Console.WriteLine(state1_.Age);
    //state1_.OnAnyPropertyChanges().Subscribe(x => Console.WriteLine(x.Age));
    //state1_.Age = 11;
  }
}

public class ConsoleState : BindableBase, IState<ConsoleStateId>
{
  public ConsoleStateId StateRepresentation => this.StateRepresentation;

  public void AddAutomaticTransition(Transition<ConsoleStateId, object> transition)
  {
    throw new NotImplementedException();
  }

  public void AddEntryAction(Action entryAction, Func<bool> condition)
  {
    throw new NotImplementedException();
  }

  public void AddEntryAction(ConsoleStateId fromState, Action entryAction, Func<bool> condition)
  {
    throw new NotImplementedException();
  }

  public void AddExitAction(Action exitAction, Func<bool> condition)
  {
    throw new NotImplementedException();
  }

  public void AddExitAction(ConsoleStateId toState, Action exitAction, Func<bool> condition)
  {
    throw new NotImplementedException();
  }

  public void AddTimedTransition(TimedTransition<ConsoleStateId, object> timedTransition)
  {
    throw new NotImplementedException();
  }

  public void AddTriggeredTransition<TTrigger>(TriggeredTransition<ConsoleStateId, TTrigger> transition) where TTrigger : class
  {
    throw new NotImplementedException();
  }

  public void Enter(ConsoleStateId fromState)
  {
    throw new NotImplementedException();
  }

  public void Exit(ConsoleStateId toState)
  {
    throw new NotImplementedException();
  }

  public IEnumerable<Action> GetValidExitActions(ConsoleStateId toState)
  {
    throw new NotImplementedException();
  }

  public void IgnoreTransitions()
  {
    throw new NotImplementedException();
  }

  public void ResumeTransitions()
  {
    throw new NotImplementedException();
  }

  public bool TryAutomaticTransition()
  {
    throw new NotImplementedException();
  }
}

public class Person : BindableBase
{
  private string _name;

  public string Name
  {
    get => _name;
    set => SetProperty(ref _name, value);
  }

  private int _age;

  public int Age
  {
    get => _age;
    set => SetProperty(ref _age, value);
  }
}

public class StateMachine1 : ReactiveStateMachine<ConsoleStateId>
{
  public int sensor1 { get; set; }

  private IObservable<PropertyChangedEventArgs> _sensorTrigger1;

  public StateMachine1() : base()
  {
    _sensorTrigger1 = Observable
      .FromEventPattern<PropertyChangedEventArgs>(this, nameof(PropertyChangedEventArgs))
      .Select(e => e.EventArgs);
  }

  public event PropertyChangedEventHandler? PropertyChanged;

  protected virtual void OnPropertyChanged([CallerMemberName] string? propertyName = null)
  {
    PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
  }

  protected bool SetField<T>(ref T field, T value, [CallerMemberName] string? propertyName = null)
  {
    if(EqualityComparer<T>.Default.Equals(field, value)) return false;
    field = value;
    OnPropertyChanged(propertyName);
    return true;
  }
}