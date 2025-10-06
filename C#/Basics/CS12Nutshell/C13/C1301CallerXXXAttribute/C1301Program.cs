using System.Runtime.CompilerServices;

class Program
{
  public static void Main()
  {
    var _mc = new MyClass();
    _mc.MyMethod();
  }
}

class MyClass
{
  public string MyProperty
  {
    get
    {
      CallMe("From a property.");
      return "";
    }
  }

  public void MyMethod()
  {
    CallMe("From a method.");
  }

  private void CallMe(string ordinaryParameter,
    [CallerMemberName] string memberName = "",    // Must be an optional parameter
    [CallerFilePath] string sourceFilePath = "",  // Must be an optional parameter
    [CallerLineNumber] int sourceLineNumber = 0   // Must be an optional parameter
  )
  {
    Console.WriteLine($"{nameof(CallMe)} called from {memberName}{Environment.NewLine}" +
                      $"  Parameter: {ordinaryParameter}{Environment.NewLine}" +
                      $"  File: {sourceFilePath}{Environment.NewLine}" +
                      $"  Line: {sourceLineNumber}{Environment.NewLine}");
  }
}