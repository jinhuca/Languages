namespace RxStateMachine.Observables;

public interface IIgnoringObservable<out T> : IObservable<T>
{
    void Ignore();
    void Resume();
}