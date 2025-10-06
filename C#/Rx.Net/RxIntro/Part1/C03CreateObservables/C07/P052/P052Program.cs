using System.Reactive;
using System.Reactive.Linq;
using static System.Console;

namespace P052;

internal class P052Program
{
  static void Main()
  {
    var subscription_ = ConvertEventToObservable(@"c:\incoming");
    ReadKey();
    subscription_.Dispose();
  }

  static IDisposable ConvertEventToObservable(string path)
  {
    FileSystemWatcher watcher_ = new(path);
    
    IObservable<EventPattern<FileSystemEventArgs>> changeEvents_ = Observable
      .FromEventPattern<FileSystemEventHandler, FileSystemEventArgs>(
        h => watcher_.Changed += h,
        h => watcher_.Changed -= h);
    
    return changeEvents_.Subscribe(WriteLine);
  }
}