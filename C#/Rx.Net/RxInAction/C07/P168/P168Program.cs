using System.Reactive.Linq;
using Helpers;
using System.Reactive.Subjects;
using static System.Console;

namespace P168;

internal class P168Program
{
  static void Main(string[] args)
  {
    //NotHideYourSubjects();
    HideYourSubjects();
  }

  private static void NotHideYourSubjects()
  {
    var acct = new BankAccount();
    acct.MoneyTransaction.SubscribeConsole("Transferring");
    var hackedSubject = acct.MoneyTransaction as Subject<int>;
    hackedSubject?.OnNext(-9999);
  }

  private static void HideYourSubjects()
  {
    Subject<int> sbj = new Subject<int>();
    sbj.SubscribeConsole();
    var proxy = sbj.AsObservable();
    var subject = proxy as Subject<int>;
    var observer= proxy as IObserver<int>;
    WriteLine($"proxy as subject is {(subject == null ? "null" : "not null")}");
    WriteLine($"proxy as observer is {(observer == null ? "null" : "not null")}");
  }
}

class BankAccount
{
  Subject<int> _inner = new Subject<int>();
  public IObservable<int> MoneyTransaction => _inner;
}