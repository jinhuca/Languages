using System.Reactive.Linq;

namespace RxStateMachine.Observables;

public class IgnoringObservable<T>(IObservable<T> source) : IIgnoringObservable<T>
{
    private bool _ignoring = true;

    public IDisposable Subscribe(IObserver<T> observer)
    {
        return source.Where(t => !Ignoring()).Subscribe(observer);
    }

    private bool Ignoring()
    {
        return _ignoring;
    }

    public void Ignore()
    {
        _ignoring = true;
    }

    public void Resume()
    {
        _ignoring = false;
    }
}