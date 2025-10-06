using static System.Threading.Thread;

namespace A0106;

internal class A0106Program
{
  public static void Main()
  {
    AsyncMethodCaller();
  }

  static async void AsyncMethodCaller()
  {
    Console.WriteLine("--- Using Task.Run(...) to create async code ---");
    bool isSame = await MyAsyncMethod(CurrentThread.ManagedThreadId);
    Console.WriteLine($"Caller thread is the same as executing thread: {isSame}");
  }

  static async Task<bool> MyAsyncMethod(int callingThreadId)
  {
    return await Task.Run(() => CurrentThread.ManagedThreadId == callingThreadId);
  }
}