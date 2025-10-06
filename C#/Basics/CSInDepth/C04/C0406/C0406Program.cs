using Newtonsoft.Json.Linq;

namespace C0406;

internal class C0406Program
{
  static void Main(string[] args)
  {
    string json_ = @"
      {
        'name': 'Jon Skeet',
        'address': {
          'town': 'Reading',
          'country': 'UK'
        }
      }".Replace('\'', '"');

    JObject obj1_ = JObject.Parse(json_);
    Console.WriteLine(obj1_["address"]["town"]);

    dynamic obj2_ = obj1_;
    Console.WriteLine(obj2_.address.town);
  }
}