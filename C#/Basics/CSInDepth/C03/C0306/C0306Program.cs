namespace C0306;

internal class C0306Program
{
  static void Main(string[] args)
  {
    var demo = new CaptureVariableDemo();
    Action<string> action = demo.CreateAction("method argument");
    action("lambda argument");
  }
}

internal class CaptureVariableDemo
{
  private string instanceField = "instance field";

  public Action<string> CreateAction(string methodParameter)
  {
    string methodLocal = "method local";
    string uncaptured = "uncaptured local";

    Action<string> action = lambdaParameter =>
    {
      string lambdaLocal = "lambda local";
      Console.WriteLine("Instance field: {0}", instanceField);
      Console.WriteLine("Method parameter: {0}", methodParameter);
      Console.WriteLine("Method local: {0}", methodLocal);
      Console.WriteLine("Lambda parameter: {0}", lambdaParameter);
      Console.WriteLine("Lambda local: {0}", lambdaLocal);
    };
    return action;
  }
}