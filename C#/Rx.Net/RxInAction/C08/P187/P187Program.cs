using System.Collections.ObjectModel;
using System.Reactive.Linq;

namespace P187;

internal class P187Program
{
  static void Main(string[] args)
  {
    Flatten();
  }

  static void Flatten()
  {
    IObservable<NewsItem> news = new List<NewsItem>
    {
      new NewsItem(){
        Images = new Collection<NewsImage> {
          new NewsImage{ IsChildFriendly = false},
          new NewsImage{ IsChildFriendly = true},
          new NewsImage{ IsChildFriendly = false},
        }
      },
      new NewsItem() {
        Images = new Collection<NewsImage> {
          new NewsImage{ IsChildFriendly = true },
          new NewsImage{ IsChildFriendly = false },
          new NewsImage{ IsChildFriendly = false },
        }
      }
    }.ToObservable();

    news.SelectMany(n => n.Images)
      .Where(img => img.IsChildFriendly)
      .Subscribe(AddToHeadlines);

  }

  private static void AddToHeadlines(NewsImage img)
  {
    Console.WriteLine("We have a child-friendly image");
  }
}

internal class NewsImage
{
  public bool IsChildFriendly { get; set; }
}

internal class NewsItem
{
  public Collection<NewsImage> Images { get; set; }
}