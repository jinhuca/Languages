namespace C2108Semaphore;

internal class C2108Program
{
  private static SemaphoreSlim _sem = new SemaphoreSlim(3);     // Capacity of 3

  static void Main(string[] args)
  {
    for (int i = 1; i <= 5; i++)
    {
      new Thread(Enter).Start(i);
    }
  }

  static void Enter(object id)
  {
    Console.WriteLine(id + " wants to enter");
    _sem.Wait();
    Console.WriteLine(id + " is in!");
    Thread.Sleep(1000 * (int)id);
    Console.WriteLine(id + " is leaving");
    _sem.Release();
  }
}