namespace C1302ConditionalAttribute;

internal class C1302Program
{
  public static bool EnableLogging;

  static void Main(string[] args)
  {
    EnableLogging = true;
    Func<string> msg1 = () => { Console.WriteLine("The first lambda was evaluated"); return "My first message"; };
    LogStatus(msg1);

    EnableLogging = false;
    Func<string> msg2 = () => { Console.WriteLine("The second lambda was evaluated"); return "My second message"; };
    LogStatus(msg2);

    Console.WriteLine("Let's see what was logged:");
    Console.WriteLine(File.ReadAllText("Conditional.log"));
  }

  static void LogStatus(Func<string> message)
  {
    string logFilePath = "Conditional.log";
    if (EnableLogging)
    {
      File.AppendAllText(logFilePath, message() + "\r\n");
    }
  }
}