using System.Reactive.Linq;
using System.Text;

namespace P109;

file class P109Program
{
  static void Main(string[] args)
  {
    //ObservableToDictionary();
    ObservableToDictionary();
  }

  static void ObservableToDictionary()
  {
    IEnumerable<string> cities = new[] { "London", "Tel-Aviv", "Tokyo", "Rome" };
    var dictionaryObservable = cities
      .ToObservable()
      .ToDictionary(c => c.Length);
    dictionaryObservable
      .Select(d => string.Join(",", d))
      .Subscribe(Console.WriteLine);
  }

  static void ObservableToLookup()
  {
    IEnumerable<string> cities = new[] { "London", "Tel-Aviv", "Tokyo", "Rome", "Madrid" };
    var lookupObservable = cities
      .ToObservable()
      .ToLookup(c => c.Length);

    lookupObservable
      .Select(lookup =>
      {
        var groups = new StringBuilder();
        foreach (var grp in lookup)
        {
          groups.AppendFormat($"[Key:{grp.Key} => {grp.Count()}");
        }

        return groups.ToString();
      })
      .Subscribe(Console.WriteLine);
  }
}