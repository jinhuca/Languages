using System.Reactive.Linq;
using System.Reactive.Subjects;
using Helpers;
using P185BasicQueryOperators.Model;

namespace P185BasicQueryOperators.Examples;

internal class SelectExample
{
  public static void Select1()
  {
    var strings_ = new[] { "aa", "Abc", "Ba", "Ac" }.ToObservable();
    var subscription_ = strings_
      .Where(s=>s.StartsWith("A"))
      .SubscribeConsole();

    Console.ReadLine();
    subscription_.Dispose();
  }

  public static void SelectUnique()
  {
    var subject = new Subject<NewsItem>();
    subject.Log()
      .Distinct(n => n.Title)
      .SubscribeConsole("Distinct");
    subject.OnNext(new NewsItem {Title = "Title1"});
    subject.OnNext(new NewsItem { Title = "Title2" });
    subject.OnNext(new NewsItem { Title = "Title1" });
    subject.OnNext(new NewsItem { Title = "Title3" });
  }

  public static void Select2()
  {
    IObservable<ChatMessage> messages_ = new[]
    {
      new ChatMessage() {
        Content = "Hello kitty comes in.", 
        Timestamp = DateTime.Today, 
        Sender = "Tom", 
        Room = "room1"
        },

      new ChatMessage
      {
        Content = "Christmas party will be on Dec. 24", 
        Timestamp = DateTime.Today, 
        Sender = "Doe", 
        Room = "room2"
      }
    }.ToObservable();

    var subscription_ = messages_
      .Select(msg => new ChatMessageViewModel(msg))
      .SubscribeConsole("fd");

    Console.ReadLine();
    subscription_.Dispose();
  }

  private static User LoadUserFromDb(string sender)
  {
    switch (sender)
    {
      case "Tom":
        return new User("Tom Jason", "1");
      case "Doe":
        return new User("Doe Joe", "2");
      default:
        return new User("", "");
    }
  }
}