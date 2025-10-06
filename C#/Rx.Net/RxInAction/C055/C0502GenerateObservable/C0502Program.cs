using System.Diagnostics.CodeAnalysis;
using System.Reactive;
using System.Reactive.Linq;
using Helpers;

namespace C0502GenerateObservable;

internal class C0502Program
{
  static void Main(string[] args)
  {
    var generator = new MagicPrimeGenerator();

    //var observablePrimes = generator.GeneratePrimesWithCreate(5);

    //var subscription = observablePrimes
    //  .Timestamp()
    //  .SubscribeConsole("Generate with Create Operator");

    //Console.ReadLine();

    var observablePrimes1 = generator.GeneratePrimesWithTask(5);
    var subscription1 = observablePrimes1
      .Timestamp()
      .SubscribeConsole("Generate with Task Run");

    Console.ReadLine();
    subscription1.Dispose();
    Console.ReadLine();
  }
}