using System.Reactive.Linq;
using SampleExtensions;

Observable
  .Range(0, 5)
  .Select(i => i + 3)
  .Dump("+3");
Console.ReadKey();

Observable.Range(1, 5)
  .Select(i => (char)(i + 64))
  .Dump("Char");
Console.ReadKey();

Observable.Range(1, 5)
  .Select(i => new { Number = i, Character = (char)(i + 64) })
  .Dump("anon");
Console.ReadKey();