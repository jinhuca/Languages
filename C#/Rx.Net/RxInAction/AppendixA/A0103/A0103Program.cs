using static System.Console;

namespace A0103;

internal class A0103Program
{
  public static async Task Main()
  {
    //GetPageAsync();
    await GetPageAsyncWithContinuation();
  }

  private static void GetPageAsync()
  {
    var httpClient = new HttpClient();
    Task<HttpResponseMessage> requestTask = httpClient.GetAsync("http://ReactiveX.io");

    WriteLine($"the request was sent, status: {requestTask.Status}");
    WriteLine(requestTask.Result.Headers);

    ReadLine();
  }

  private static async Task GetPageAsyncWithContinuation()
  {
    var httpClient = new HttpClient();
    await httpClient.GetAsync("http://ReactiveX.io")
      .ContinueWith(requestTask =>
      {
        WriteLine($"the request was sent, status {requestTask.Status}");
        WriteLine(requestTask.Result.Headers);
      });
  }
}