using System;
using System.Reactive;
using System.Reactive.Linq;
using System.Windows;

namespace P100;

internal partial class MainWindow
{
  public MainWindow()
  {
    InitializeComponent();
    SubscribeObservable();
  }

  private void SubscribeObservable()
  {
    var clicks =
      Observable.FromEventPattern<RoutedEventHandler, RoutedEventArgs>(
        h => theButton.Click += h,
        h => theButton.Click -= h);

    //_ = clicks.Subscribe(_ => output.Text += "Button clicked." + Environment.NewLine);

    clicks.Subscribe(evt =>
    {
      output.Text += evt.EventArgs.RoutedEvent.OwnerType.Name + " \n";
    });

    //var clicks1 = Observable.FromEventPattern<RoutedEventArgs>(
    //  theButton, nameof(theButton.Click));
    //clicks1.Subscribe(_ => output.Text += "Button clicked. " + Environment.NewLine);

    //IObservable<EventPattern<object>> cc = Observable.FromEventPattern(theButton, nameof(theButton.Click));
    //cc.Subscribe(_ => output.Text += "Button clicked." + Environment.NewLine);
  }
}