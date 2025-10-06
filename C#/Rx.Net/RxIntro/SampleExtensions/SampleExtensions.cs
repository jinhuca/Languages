namespace SampleExtensions;

public static class SampleExtensions
{
  public static void Dump<T>(this IObservable<T> source, string name)
  {
    source.Subscribe(
      value => Console.WriteLine($"{name}-->{value}"),
      ex => Console.WriteLine($"{name} failed -->{ex.Message}"),
      () => Console.WriteLine($"{name} completed"));
  }
}