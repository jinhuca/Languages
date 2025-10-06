namespace P121.SearchEngine;

internal class SearchEngineA : ISearchEngine
{
  public async Task<IEnumerable<string>> SearchAsync(string term)
  {
    WriteLine("Search Engine A - SearchAsync()");
    await Task.Delay(1500);
    return new[] { "result A", "result B" };
  }
}