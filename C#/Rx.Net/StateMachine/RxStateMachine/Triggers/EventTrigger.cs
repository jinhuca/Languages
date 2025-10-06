using System.Reactive.Linq;
using RxStateMachine.Observables;

namespace RxStateMachine.Triggers;

public class EventTrigger<T> : Trigger<T> where T : EventArgs
{
  public EventTrigger(object target, String eventName) 
    : base(Observable.FromEventPattern<T>(target, eventName).Select(evt => evt.EventArgs).AsIgnoringObservable())
  {
  }
}