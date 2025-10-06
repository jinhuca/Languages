using System.Reactive.Disposables;
using System.Reactive.Linq;
using static System.Console;

namespace P107;

file class P107Program
{
  static void Main(string[] args)
  {
    //ToEnumerableDemo();
    ToListDemo();
  }

  static void ToEnumerableDemo()
  {
    var observable = Observable.Create<string>(o =>
    {
      o.OnNext("Observable");
      o.OnNext("To");
      o.OnNext("Enumerable");
      o.OnCompleted();
      return Disposable.Empty;
    });

    var enumerable = observable.ToEnumerable();
    foreach (var item in enumerable)
    {
      WriteLine(item);
    }
  }

  static void ToListDemo()
  {
    var observable = Observable.Create<string>(s =>
    {
      s.OnNext("Observable");
      s.OnNext("To");
      s.OnNext("List");
      s.OnCompleted();
      return Disposable.Empty;
    });
    IObservable<IList<string>> listObservable = observable.ToList();
    listObservable.Select(lst => string.Join(".", lst)).Subscribe(WriteLine);
  }
}