using System.Reactive.Linq;
using static System.Console;

namespace P105;

file class P105Program
{
  static void Main()
  {
    ConvertEnumerableToObservable();
    ThrowException();
  }

  private static void ConvertEnumerableToObservable()
  {
    IEnumerable<string> names = new[] { "Shira", "Yonatan", "Gabi", "Tamir" };
    IObservable<string> observables = names.ToObservable();
    observables.Subscribe(WriteLine);
  }

  private static void ThrowException()
  {
    NumbersAndThrow().ToObservable().Subscribe(WriteLine);
  }

  private static IEnumerable<int> NumbersAndThrow()
  {
    yield return 1;
    yield return 2;
    yield return 3;
    throw new ApplicationException("Something bad happened.");
    yield return 4;
  }
}