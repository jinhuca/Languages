using System.Reactive.Threading.Tasks;

namespace P054;

internal class P054Program
{
  static void Main()
  {
    Task<string> t_ = Task.Run(() =>
    {
      Console.WriteLine("Task running ...");
      return "Test";
    });
    IObservable<string> source_ = t_.ToObservable();

    source_.Subscribe(
      Console.WriteLine,
      () => Console.WriteLine("completed"));

    source_.Subscribe(
      Console.WriteLine,
      () => Console.WriteLine("completed"));
    
    Console.Read();
  }
}