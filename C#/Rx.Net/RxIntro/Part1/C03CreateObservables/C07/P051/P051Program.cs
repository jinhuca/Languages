using System.Reactive;
using System.Reactive.Linq;
using static System.Console;

namespace P051;

internal class P051Program
{
  static void Main()
  {
    var subscription_ = ConvertEventToObservable(@"c:\incoming");
    ReadKey();
    subscription_.Dispose();
  }

  private static IDisposable ConvertEventToObservable(string path)
  {
    FileSystemWatcher watcher_ = new(path);

    IObservable<EventPattern<FileSystemEventArgs>> changeEvents_ = Observable
      .FromEventPattern<FileSystemEventArgs>(watcher_, nameof(watcher_.Changed));

    return changeEvents_.Subscribe(WriteLine);
  }
}