using Helpers;
using System.Reactive.Disposables;
using System.Reactive.Linq;
using System.Threading.Channels;

namespace P097;

file class C0403Program
{
  public static void Main()
  {
    //DemoObservableGeneration();
    DemoObservableCreation();
    //var numbers = Observables.CreateObservableNumbers(5);
    //var subscription = numbers.Subscribe(Console.WriteLine);

    //var numbers = CreateObservableNumbers(5);
    //var subscription = numbers.Subscribe(new ConsoleObserver<int>(nameof(numbers)));
    //GenerateSequence();
    //CreateRangeObservables();
    //ReadAFileWithGenerate();
  }

  public static void DemoObservableCreation()
  {
    var numbers = Observables.CreateObservableNumbers(5);
    var subscription = numbers.Subscribe(Console.WriteLine);
  }

  public static void DemoObservableGeneration()
  {
    var numbers = Observables.CreateSequence(5);
    var subscription = numbers.Subscribe(Console.WriteLine);
  }

  public static void GenerateSequence()
  {
    IObservable<int> observable = Observable.Generate(
      0,              // initial state
      i => i < 10,    // condition (false means terminate)
      i => i + 1,     // next iteration step
      i => i + 2);    // the value in each iteration

    observable.SubscribeConsole("Generate sequence");
  }

  public static void CreateRangeObservables()
  {
    Console.WriteLine();
    
    IObservable<int> observable = Observable
      .Range(0, 10)
      .Select(i => i * 2);

    // this will print the values: 0,2,4,6,8,10,12,14,16,18
    observable.SubscribeConsole("range");

  }

  private static void ReadAFileWithGenerate()
  {
    Console.WriteLine();
    Console.WriteLine("Generate Sequence from a file");


    //
    // this will read the file, but the created StreamReader wont get disposed when readings complete
    //
    //IObservable<string> lines =
    //    Observable.Generate(
    //        File.OpenText("TextFile.txt"), //beware, this will open the stream but nothing will dispose it
    //        s => !s.EndOfStream,
    //        s => s,
    //        s => s.ReadLine());


    IObservable<string> lines =
      Observable.Using(
        () => File.OpenText("TextFile.txt"),    // opens the file and returns the stream we work with
        stream =>
          Observable.Generate(
            stream,                 //initial state
            s => !s.EndOfStream,    //we continue until we reach the end of the file
            s => s,                 //the stream is our state, it holds the position in the file 
            s => s.ReadLine())      //each iteration will emit the current line (and moves to the next)
      );

    lines.SubscribeConsole("lines");
  }
}