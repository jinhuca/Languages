using System.Reactive.Linq;

namespace C0202ObservableEventArgs;

internal class C0202Program
{
  public static event EventHandler<EventArgs> SimpleEvent;

  static void Main()
  {
    var eventAsObservable_ = Observable.FromEventPattern<EventArgs>(
      ev => SimpleEvent += ev,
      ev => SimpleEvent -= ev);
  }
}
