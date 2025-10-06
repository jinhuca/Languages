using System.Reactive.Linq;
using static System.Console;

namespace C0203ObserveEvent
{
  internal class Program
  {
    public static event EventHandler SimpleEvent;

    private static void Main()
    {
      WriteLine("Setup observable");

      // To consume SimpleEvent as an IObservable:
      var eventAsObservable = Observable.FromEventPattern(
        ev => SimpleEvent += ev, 
        ev => SimpleEvent -= ev);

      // SimpleEvent is null until we subscribe
      WriteLine(SimpleEvent == null ? "SimpleEvent == null" : "SimpleEvent != null");
      WriteLine("Subscribe");

      //Create two event subscribers
      var s = eventAsObservable.Subscribe(args => WriteLine("Received event for s subscriber"));
      var t = eventAsObservable.Subscribe(args => WriteLine("Received event for t subscriber"));

      // After subscribing the event handler has been added
      WriteLine(SimpleEvent == null ? "SimpleEvent == null" : "SimpleEvent != null");
      WriteLine("Raise event");

      if(null != SimpleEvent)
      {
        SimpleEvent(null, EventArgs.Empty);
      }

      // Allow some time before unsubscribing or event may not happen
      Thread.Sleep(100);
      WriteLine("Unsubscribe");

      s.Dispose();
      t.Dispose();

      // After unsubscribing the event handler has been removed
      WriteLine(SimpleEvent == null ? "SimpleEvent == null" : "SimpleEvent != null");
      ReadKey();
    }
  }
}
