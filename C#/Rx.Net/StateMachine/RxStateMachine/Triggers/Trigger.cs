using RxStateMachine.Observables;

namespace RxStateMachine.Triggers;

public class Trigger<TTrigger>
{
  public Trigger(IObservable<TTrigger> source)
  {
    Sequence = source is IIgnoringObservable<TTrigger> source_ 
      ? source_ 
      : new IgnoringObservable<TTrigger>(source);
  }

  public IIgnoringObservable<TTrigger> Sequence { get; private set; }
}