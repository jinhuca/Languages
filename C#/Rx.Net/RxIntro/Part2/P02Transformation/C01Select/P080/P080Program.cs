using System.Reactive.Linq;
using SampleExtensions;

Observable
  .Range(1, 5)
  .Select(i => new string((char)(i + 64), 1))
  .Dump("Char");
Console.ReadKey();

Observable
  .Range(1, 5)
  .Select(i => new string((char)(i + 64), i))
  .Dump("strings");
Console.ReadKey();

Observable
  .Range(1, 5)
  .Select(i => new string((char)(i + 64), i)
    .ToObservable())
  .Dump("sequences");
Console.ReadKey();

Observable
  .Range(1, 5)
  .SelectMany(i => new string((char)(i + 64), i)
    .ToObservable())
  .Dump("chars");
Console.ReadKey();

IEnumerable<char> x = Enumerable
  .Range(1, 5)
  .SelectMany(i => new string((char)(i + 64), i));
foreach(var i in x)
{
  Console.WriteLine(i);
}