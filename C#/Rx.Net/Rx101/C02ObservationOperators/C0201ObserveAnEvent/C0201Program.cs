using System.Reactive.Linq;

public class Program
{
  public static event EventHandler SimpleEvent;

  public static void Main()
  {
    var eventAsObservable_ = Observable.FromEventPattern(
      ev => SimpleEvent += ev,
      ev => SimpleEvent -= ev);
  }
}