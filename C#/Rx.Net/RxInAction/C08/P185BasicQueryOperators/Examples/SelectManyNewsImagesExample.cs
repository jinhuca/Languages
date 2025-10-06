using System.Reactive.Linq;

namespace P185BasicQueryOperators.Examples;

internal class SelectManyNewsImagesExample
{
  public static void P187_FlattenSimpleCollections()
  {
    var theNews = new[]
    {
      new NewsItem
        {
        Title = "NewItem1",
        Url = new Url(),
        Images = new[] {new NewsImage("Item1Image1", true)}
        },

      new NewsItem
      {
        Title = "NewItem2",
        Url = new Url(),
        Images = new[] {new NewsImage("Item2Image1", true)}
      },
    }.ToObservable();

    var subscription_ = theNews
      .SelectMany(n => n.Images)
      .Where(img => img.IsChildFriendly)
      .Subscribe(img => Console.WriteLine($"{img.ImageName} image is child friendly."));

    Console.ReadLine();
    subscription_.Dispose();
  }

  public static void Flatten()
  {
    var theNews = new[]
    {
      new NewsItem
      {
        Title = "NewItem1",
        Url = new Url(),
        Images = new[]
        {
          new NewsImage("Item1Image1", true)
        }
      },

      new NewsItem
      {
      Title = "NewItem2",
      Url = new Url(),
      Images = new[]
      {
        new NewsImage("Item2Image1", true)
      }
      }
    }.ToObservable();

    var newsImages_ =
      from n in theNews
      from img in n.Images
      where img.IsChildFriendly
      select new NewImageViewModel
      {
        NewsImage = img,
        ItemUrl = n.Url
      };

    var subscription_ = newsImages_
      .Subscribe(img => Console.WriteLine($"{img.NewsImage.ImageName}"));
    Console.ReadLine();
    subscription_.Dispose();
  }
}

public class NewsItem()
{
  public string Title { get; set; }
  public Url Url { get; set; }
  public IEnumerable<NewsImage> Images { get; set; }
  public override string ToString() => Title;
}

public class Url
{
}

public class NewsImage(string imageName, bool isChildFriendly = true)
{
  public string ImageName { get; set; } = imageName;
  public bool IsChildFriendly { get; set; } = isChildFriendly;
}

internal class NewImageViewModel
{
  public NewImageViewModel(NewsImage img, Url itemUrl)
  {
    NewsImage = img;
    ItemUrl = itemUrl;
  }

  public NewImageViewModel()
  {
  }

  public NewsImage NewsImage { get; set; }
  public Url ItemUrl { get; set; }
}