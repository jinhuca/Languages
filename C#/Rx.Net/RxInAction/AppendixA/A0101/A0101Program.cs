using static System.Console;
using static System.Threading.Thread;

WriteLine($"Create a thread in main thread id# = {CurrentThread.ManagedThreadId}, and wait for its completion.");
//var thread = new Thread(() =>
//{
//  WriteLine($"Start work on thread id# = {CurrentThread.ManagedThreadId} ...");
//  Task.Delay(2000);
//  Write($"Long work is done, the result is ... 41.\n");
//});
//thread.Start();
//ReadLine();

WriteLine($"Queue a work item in thread pool, and wait for its completion.");
ThreadPool.QueueUserWorkItem(_ =>
{
  WriteLine($"Start work on thread id# = {CurrentThread.ManagedThreadId} ...");
  Sleep(2000);
  Write($"Long work is done, the result is 43.\n");
});
ReadLine();
