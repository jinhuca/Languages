using static System.Console;

namespace C0501.ThreadAsync;

file class C0501Program
{
  private const string Url = "http://reactivex.io";

  static async Task Main()
  {
    //CreateThread();
    //UseThreadPool();
    //GetPageWithTask();
    //GetPageWithContinuation();
    //ContinuationIsLength();
    //await GetPageWithAwait();
    //MakeAsyncWithTaskRun.AsyncMethodCaller().Wait();
    AsyncMethodIsNotAlwaysAsync.AsyncMethodCaller().Wait();
  }
   
  private static void CreateThread()
  {
    var thread = new Thread(() =>
    {
      Thread.Sleep(TimeSpan.FromSeconds(5));
      WriteLine("Long work is done.");
    });
    WriteLine("Starting the long work.");
    thread.Start();
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

  private static void GetPageWithTask()
  {
    var httpClient = new HttpClient();
    Task<HttpResponseMessage> requestTask = httpClient.GetAsync(Url);
    WriteLine($"The request was sent, status {requestTask.Status}");
    WriteLine(requestTask.Result.Headers);
  }

  private static void GetPageWithContinuation()
  {
    var httpClient = new HttpClient();
    httpClient.GetAsync("http://reactivex.io").ContinueWith(requestTask =>
    {
      WriteLine($"The request was sent, status: {requestTask.Status}");
      WriteLine(requestTask.Result.Headers);
    });
    ReadLine();
  }

  private static void ContinuationIsLength()
  {
    var httpClient = new HttpClient();
    httpClient.GetAsync(Url).ContinueWith(requestTask =>
    {
      HttpContent httpContent = requestTask.Result.Content;
      httpContent.ReadAsStringAsync().ContinueWith(contentTask =>
      {
        WriteLine(contentTask.Result);
      });
    });
    ReadLine();
  }

  private static async Task GetPageWithAwait()
  {
    var httpClient = new HttpClient();
    var response = await httpClient.GetAsync(Url);
    var page = await response.Content.ReadAsStringAsync();
    WriteLine(page);
  }
}

internal class MakeAsyncWithTaskRun
{
  public static async Task AsyncMethodCaller()
  {
    bool isSame = await MyAsyncMethod(Thread.CurrentThread.ManagedThreadId);
    WriteLine($"Caller thread is the same as executing thread: {isSame}");
  }

  private static async Task<bool> MyAsyncMethod(int callingThreadId)
  {
    return await Task.Run(() => Thread.CurrentThread.ManagedThreadId == callingThreadId);
  }
}

internal class AsyncMethodIsNotAlwaysAsync
{
  public static async Task AsyncMethodCaller()
  {
    bool isSame = await MyAsyncMethod(Thread.CurrentThread.ManagedThreadId);
    WriteLine($"Caller thread is the same as executing thread: {isSame}");
  }

  static async Task<bool> MyAsyncMethod(int callingThreadId)
  {
    return Thread.CurrentThread.ManagedThreadId == callingThreadId;
  }
}