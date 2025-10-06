using System.Reactive.Disposables;

namespace B0101;

internal class B0101Program
{
  static async Task Main()
  {
    await RefreshNewsAsync();
  }

  private static async Task RefreshNewsAsync()
  {
    var IsBusy = true;
    var NewsItems = Enumerable.Empty<string>();
    using (Disposable.Create(() => IsBusy = false))
    {
      NewsItems = await DownloadNewsItems();
    }
  }

  private static async Task<IEnumerable<string>> DownloadNewsItems()
  {
    var items = new List<string> { "Hello", "Rx" };
    return items.AsEnumerable();
  }
}