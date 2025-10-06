using static System.Console;

namespace C2107ThreadSafetyInServersEnhanced;

internal class C2107Program
{
  static async Task Main(string[] args)
  {
    new Thread(() => { WriteLine(UserCache.GetUserAsync(1)); }).Start();
    new Thread(() => { WriteLine(UserCache.GetUserAsync(2)); }).Start();
    new Thread(() => { WriteLine(UserCache.GetUserAsync(3)); }).Start();

    // You can also await this method:
    User user = await UserCache.GetUserAsync(1);
    WriteLine(user);
  }
}

static class UserCache
{
  static Dictionary<int, Task<User>> _userTasks =
    new Dictionary<int, Task<User>>();

  internal static Task<User> GetUserAsync(int id)
  {
    lock (_userTasks)
      if (_userTasks.TryGetValue(id, out var userTask))
        return userTask;
      else
        return _userTasks[id] = Task.Run(() => RetrieveUser(id));
  }

  static User RetrieveUser(int id)
  {
    Thread.Sleep(1000);  // simulate a time-consuming operation
    return new User { ID = id };
  }

}

class User
{
  public int ID;
  public override string ToString()
  {
    return ID.ToString();
  }
}