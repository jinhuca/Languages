public class Program
{
  public static async Task Main(string[] args)
  {
    string html = await GetWebPageAsync("http://www.linqpad.net");
    Console.WriteLine($"{html.Length} Characters downloaded.");

    // Let's try again. It should be instant this time:
    html = await GetWebPageAsync("http://www.linqpad.net");
    Console.WriteLine($"{html.Length} Characters downloaded.");
  }

  static Dictionary<string, Task<string>> _cache =
   new Dictionary<string, Task<string>>();

  static Task<string> GetWebPageAsync(string uri)
  {
    lock (_cache)
    {
      Task<string> downloadTask;
      if (_cache.TryGetValue(uri, out downloadTask)) return downloadTask;
      return _cache[uri] = new HttpClient().GetStringAsync(uri);
    }
  }
}