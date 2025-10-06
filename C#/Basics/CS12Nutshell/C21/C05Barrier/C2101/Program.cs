namespace C2101
{
  internal class Program
  {
    private static Barrier _barrier = new Barrier(3, barrier => Console.WriteLine());

    static void Main()
    {
      new Thread(Speak).Start();
      new Thread(Speak).Start();
      new Thread(Speak).Start();
    }

    static void Speak()
    {
      for (int i = 0; i < 5; i++)
      {
        Console.Write(i + " ");
        Thread.Sleep(1000);
        _barrier.SignalAndWait();
      }
    }
  }
}