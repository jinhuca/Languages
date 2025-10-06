using static System.Console;

namespace C0500.Threads;

file class C0500Program
{
  static void Main()
  {
    //CreateThread();
    UseThreadPool();
  }

  private static void CreateThread()
  {
    var thread_ = new Thread(() =>
    {
      Thread.Sleep(TimeSpan.FromSeconds(5));
      WriteLine("Long work is done.");
    });
    WriteLine("Starting the long work.");
    thread_.Start();
    WriteLine("Waiting for long work to finish, but you can press <Enter> any time to continue.");
    ReadLine();
  }

  private static void UseThreadPool()
  {
    WriteLine("Starting the long work.");
    ThreadPool.QueueUserWorkItem(_ =>
    {
      Thread.Sleep(TimeSpan.FromSeconds(5));
      WriteLine("Long work is done.");
    });
    WriteLine("Waiting for long work to finish, but you can press <Enter> any time to continue.");
    ReadLine();
  }
}