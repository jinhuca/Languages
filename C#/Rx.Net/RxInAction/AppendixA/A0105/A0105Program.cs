using static System.Console;

namespace A0105;

internal class A0105Program
{
  static void Main()
  {
    AsyncMethodCaller();
  }

  private static async void AsyncMethodCaller()
  {
    bool isSame = await MyAsyncMethod(Thread.CurrentThread.ManagedThreadId);
    WriteLine(isSame);
  }

  private static async Task<bool> MyAsyncMethod(int callingThreadId)
  {
    return Thread.CurrentThread.ManagedThreadId == callingThreadId;
  }
}