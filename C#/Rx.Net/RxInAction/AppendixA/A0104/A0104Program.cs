using static System.Console;

namespace A0104;

internal class A0104Program
{
  public static async Task Main()
  {
    await GetPageAsync();
  }

  private static async Task GetPageAsync()
  {
    var httpClient = new HttpClient();
    var response = await httpClient.GetAsync("http://ReactiveX.io");
    var page = await response.Content.ReadAsStringAsync();
    WriteLine(page);
  }
}