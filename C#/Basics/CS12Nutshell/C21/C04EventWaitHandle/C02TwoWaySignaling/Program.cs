namespace C02TwoWaySignaling
{
  public class Program
  {
    private static EventWaitHandle _ready = new AutoResetEvent(false);
    private static EventWaitHandle _go = new AutoResetEvent(false);
    private static readonly object _locker = new object();
    private static string _message;
    
    static void Main(string[] args)
    {
      new Thread(Work).Start();

      _ready.WaitOne();                  // First wait until worker is ready
      lock (_locker) _message = "ooo";
      _go.Set();                         // Tell worker to go

      _ready.WaitOne();
      lock (_locker) _message = "ahhh";  // Give the worker another message
      _go.Set();

      _ready.WaitOne();
      lock (_locker) _message = null;    // Signal the worker to exit
      _go.Set();
    }

    static void Work()
    {
      while (true)
      {
        _ready.Set();
        _go.WaitOne();
        lock (_locker)
        {
          if(_message==null) return;
          Console.WriteLine(_message);
        }
      }
    }
  }
}