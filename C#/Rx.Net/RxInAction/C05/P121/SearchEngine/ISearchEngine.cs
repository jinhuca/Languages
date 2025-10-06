namespace P121.SearchEngine;

internal interface ISearchEngine
{
  Task<IEnumerable<string>> SearchAsync(string term);
}