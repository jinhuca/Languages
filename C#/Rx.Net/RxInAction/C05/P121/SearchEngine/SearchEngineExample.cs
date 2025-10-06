using System.Reactive.Linq;
using System.Reactive.Threading.Tasks;

namespace P121.SearchEngine;

internal class SearchEngineExample
{
  public static IObservable<string> Search_WithAsyncAwait(string term)
  {
    return Observable.Create<string>(async obj=>
    {
      var searchEngineA = new SearchEngineA();
      var searchEngineB = new SearchEngineB();
      var resultA = await searchEngineA.SearchAsync(term);
      foreach (var result in resultA)
      {
        obj.OnNext(result);
      }
      var resultB=await searchEngineB.SearchAsync(term);
      foreach (var result in resultB)
      {
        obj.OnNext(result);
      }
      obj.OnCompleted();
    });
  }

  public static IObservable<string> Search_ConcatTasks(string term)
  {
    var searchEngineA = new SearchEngineA();
    var searchEngineB = new SearchEngineB();
    IObservable<IEnumerable<string>> resultA = searchEngineA.SearchAsync(term).ToObservable();
    IObservable<IEnumerable<string>> resultB = searchEngineB.SearchAsync(term).ToObservable();
    return resultA.Concat(resultB).SelectMany(x => x);
  }
}