namespace P121.SearchEngine;

class SearchEngineB : ISearchEngine
{
  public async Task<IEnumerable<string>> SearchAsync(string term)
  {
    WriteLine("Search Engine B - SearchAsync()");
    await Task.Delay(1500);
    return new[] { "result C", "result D" }.AsEnumerable();
  }
}