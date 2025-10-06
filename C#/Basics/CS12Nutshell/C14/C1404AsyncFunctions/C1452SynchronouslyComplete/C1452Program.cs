public class C1452Program
{
  public async static Task Main()
  {
    string html = await GetWebPageAsync("http://www.linqpad.net");
    Console.WriteLine($"{html.Length} Characters downloaded.");

    // Let's try again. It should be instant this time:
    html = await GetWebPageAsync("http://www.linqpad.net");
    Console.WriteLine($"{html.Length} Characters downloaded.");
  }

  static Dictionary<string, string> _cache = new Dictionary<string, string>();

  static async Task<string> GetWebPageAsync(string uri)
  {
    string html;
    if (_cache.TryGetValue(uri, out html)) return html;
    return _cache[uri] = await new HttpClient().GetStringAsync(uri);
  }
}
