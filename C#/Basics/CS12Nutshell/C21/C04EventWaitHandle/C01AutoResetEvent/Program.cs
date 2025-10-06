using static System.Console;

namespace C01AutoResetEvent;

public class Program
{
  private static readonly EventWaitHandle _waitHandle = new AutoResetEvent(false);

  static void Main(string[] args)
  {
    StartThreadMethod();
  }

  static void StartWaiter()
  {
    new Thread(Waiter).Start();
    Thread.Sleep(1000);
    _waitHandle.Set();              // Wake up the Waiter.
  }

  static void Waiter()
  {
    WriteLine("Waiting ...");
    _waitHandle.WaitOne();
    WriteLine("Notified.");
  }

  static void StartThreadMethod()
  {
    new Thread(ThreadMethod).Start();
    Thread.Sleep(2100);
    _waitHandle.Set();
  }

  static void ThreadMethod()
  {
    if (!_waitHandle.WaitOne(TimeSpan.FromSeconds(2)))
    {
      WriteLine("Continue");
      Thread.Sleep(TimeSpan.FromSeconds(1));
    }
    else
    {
      WriteLine("Thread got signal");
    }
  }
}