using static System.Console;

namespace E00;

internal class Program
{
  static void Main()
  {
    string msg1 = "hello world";
    var result1 = API.PrintMessage(msg1);
    WriteLine($"- return value = {result1}");

    string msg2 = null;
    var result2 = API.PrintMessage(msg2);
    WriteLine($"- return value = {result1}");

    var s1 = "abc";
    var s2 = "aBc";
    var result3 = API.StringEqualityCompare(
      s1,
      s2,
      (str1, str2) => string.Equals(str1, str2));
    WriteLine($"Is equal = {result3}");
    

    MyDelegate m1 = s => {
      WriteLine($"m1 = {s}");
      return !string.IsNullOrEmpty(s);
    };

    MyDelegate m2 = delegate(string s)
    {
      if (string.IsNullOrEmpty(s)) {
        WriteLine($"m2 has null or empty string");
        return false;
      }
      WriteLine($"m2 = {s}");
      return true;
    };

    bool m3(string s) {
      WriteLine($"m3 = {s}");
      return true;
    }
    
    MyDelegate del = new MyDelegate(m3);
    del += m1;
    del += m2;
    del("hello C# Delegate!");
  }
}

public delegate bool MyDelegate(string? str);

public static class API
{
  public static bool PrintMessage(string msg)
  {
    if(msg != null)
    {
      WriteLine(msg);
      return true;
    }
    WriteLine("Message passed is null");
    return false;
  }

  public static bool StringEqualityCompare(
    string? str1,
    string? str2,
    Func<string?, string?, bool> comparerFunc)
  {
    if(str1 is null && str2 is not null)
    {
      return false;
    }

    if(str1 is not null && str2 is null)
    {
      return false;
    }

    return comparerFunc(str1, str2);
  }

  /*
  public static void InvokeDelegate(MyDelegate myDelegate, string myParam)
  {
    if(myDelegate is null)
    {
      WriteLine("delegate instance is null.");
      return;
    }

    var registeredMethodNumber = myDelegate.GetInvocationList().Length;
    WriteLine($"number of registered methods = {registeredMethodNumber}");

    var result = myDelegate.Invoke(myParam);
  }
  */
}