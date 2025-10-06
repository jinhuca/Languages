using System.Numerics;
using System.Reactive.Linq;
using static System.Console;

namespace P046;

internal class P046Program
{
  static void Main()
  {
    var subscription_ = Fibonacci().Subscribe(v => WriteLine(v));
  }

  static IObservable<BigInteger> Fibonacci()
  {
    return Observable.Generate(
      (v1: new BigInteger(1), v2: new BigInteger(1)),
      value => true,
      value => (value.v2, value.v1 + value.v2),
      value => value.v1);
  }
}