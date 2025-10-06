namespace RxStateMachine.Observables;

public static class ObservableExtensions
{
    public static IIgnoringObservable<T> AsIgnoringObservable<T>(this IObservable<T> source)
    {
        return new IgnoringObservable<T>(source);
    }
}