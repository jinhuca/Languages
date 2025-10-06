using System.Reactive.Linq;
using System.Reactive.Subjects;
using Helpers;
using P185BasicQueryOperators.Model;

namespace P185BasicQueryOperators.Examples;

internal class ChatRoomsExample
{
  public static void FlattenObservableOfObservables()
  {
    var roomsSubject = new Subject<ChatRoom>();
    IObservable<ChatRoom> rooms = roomsSubject.AsObservable();

    var subscription_ = rooms
      .Log("Rooms")
      .SelectMany(r => r.Messages)
      .Select(m => new ChatMessageViewModel(m))
      .Subscribe(AddToDashboard);

    var room1 = new Subject<ChatMessage>();
    roomsSubject.OnNext(new ChatRoom {Id ="Room1", Messages = room1.Do(m=>m.Room="Room1")});
    room1.OnNext(new ChatMessage { Content = "First Message", Sender = "1" });
    room1.OnNext(new ChatMessage { Content = "Second Message", Sender = "1" });

    var room2 = new Subject<ChatMessage>();
    roomsSubject.OnNext(new ChatRoom { Id = "Room2", Messages = room2.Do(m => m.Room = "Room2") });
    room2.OnNext(new ChatMessage { Content = "Hello World", Sender = "2" });
    room1.OnNext(new ChatMessage { Content = "Another Message", Sender = "1" });

    Console.ReadLine();
    subscription_.Dispose();
  }

  private static void AddToDashboard(ChatMessageViewModel vm)
  {
    Console.WriteLine(vm);
  }
}