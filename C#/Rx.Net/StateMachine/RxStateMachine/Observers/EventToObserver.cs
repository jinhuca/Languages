using System.Reflection;
using System.Windows;
using Microsoft.Xaml.Behaviors;

namespace RxStateMachine.Observers;

public class EventToObserver : TriggerAction<FrameworkElement>
{
    private MethodInfo? _onNextMethod;

    protected override void Invoke(object parameter)
    {
        if (_onNextMethod != null)
        {
            _onNextMethod.Invoke(Observer, [parameter]);
        }
    }

    #region Observer

    public static readonly DependencyProperty ObserverProperty = DependencyProperty.Register(
      nameof(Observer),
      typeof(object),
      typeof(EventToObserver),
      new FrameworkPropertyMetadata(null, OnObserverChanged));

    public object? Observer
    {
        get => GetValue(ObserverProperty);
        set => SetValue(ObserverProperty, value);
    }

    private static void OnObserverChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
    {
        EventToObserver target = (EventToObserver)d;
        object oldObserver = e.OldValue;
        object? newObserver = target.Observer;
        target.OnObserverChanged(oldObserver, newObserver);
    }

    protected virtual void OnObserverChanged(object oldObserver, object? newObserver)
    {
        if (newObserver != null)
            _onNextMethod = Observer?.GetType().GetMethod("OnNext");
    }

    #endregion
}