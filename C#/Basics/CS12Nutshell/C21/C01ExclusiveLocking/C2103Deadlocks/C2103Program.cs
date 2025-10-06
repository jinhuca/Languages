namespace C2103Deadlocks;

internal class C2103Program
{
  static object locker1 = new object();
  static object locker2 = new object();

  static void Main(string[] args)
  {
    DeadlockDemo();
  }

  static void DeadlockDemo()
  {
    new Thread(() =>
    {
      lock (locker1)
      {
        Console.WriteLine("locking in 1");
        Thread.Sleep(1000);
        lock (locker2) { }            // Deadlock
      }
    }).Start();
    lock (locker2)
    {
      Console.WriteLine("locking in 2");
      Thread.Sleep(1000);
      lock (locker1) { }              // Deadlock
    }
  }
}