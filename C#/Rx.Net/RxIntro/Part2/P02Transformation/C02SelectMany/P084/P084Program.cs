using System.Reactive.Linq;
using SampleExtensions;
using static System.Console;
using static System.TimeSpan;

Observable
  .Range(1, 5)
  .SelectMany(i => 
    Observable
      .Repeat((char)(i + 64), i)
      .Delay(FromMicroseconds(i * 1000)))
  .Dump("chars ");

ReadKey();
