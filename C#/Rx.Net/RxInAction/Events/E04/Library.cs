namespace E04;

internal class Library
{
  public int CallbackApiMethod(string str, Func<char, bool> pluginFunc)
  {
    return str
      .Where(pluginFunc)
      .Count();
  }
}