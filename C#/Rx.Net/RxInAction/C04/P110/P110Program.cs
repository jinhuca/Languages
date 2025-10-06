using System.Reactive.Linq;
using Helpers;
using static System.Console;

namespace P110;

file class P110Program
{
  static void Main()
  {
    //GenerateObservableLoop();
    //GenerateRange();
    //ReadFile();
    //ReadFileCorrect();
    //CreateSingleItemObservable();
    //CreateNeverEndingObservable();
    //ThrowException();
    CreateEmptyObservable();
  }

  static void GenerateObservableLoop()
  {
    var observable = Observable.Generate(
      0,                    // Initial state
      i => i < 10,      // Condition (false means terminate)
      i => i + 1,       // Next iteration step
      i => i * 2);      // The value in each iteration

    observable.Subscribe(WriteLine);
  }

  static void GenerateRange()
  {
    var observable = Observable
      .Range(0, 10)
      .Select(i => i * 2);

    observable.Subscribe(WriteLine);
  }

  static void ReadFile()
  {
    var lines = Observable.Generate(
      File.OpenText("TextFile.txt"),
      s => !s.EndOfStream,
      s => s,
      s => s.ReadLine());

    lines.Subscribe(WriteLine);
  }

  static void ReadFileCorrect()
  {
    IObservable<string?> lines = Observable.Using(
      () => File.OpenText("TextFile.txt"),
      stream => Observable.Generate(
        stream,
        s => !s.EndOfStream,
        s => s,
        s => s.ReadLine()));

    lines.Subscribe(WriteLine);
  }

  static void CreateSingleItemObservable()
  {
    Observable.Return("Hello World").Subscribe(WriteLine);
  }

  static void CreateNeverEndingObservable()
  {
    Observable.Never<string>().Subscribe(WriteLine);
  }

  static void ThrowException()
  {
    Observable.Throw<ApplicationException>(new ApplicationException("Something bad happened"))
      .Subscribe(
        WriteLine,
        ex => WriteLine(ex.Message),
        () => WriteLine("completed."));
  }

  static void CreateEmptyObservable()
  {
    Observable.Empty<string>().SubscribeConsole("Empty");
  }
}
