((ILogger)new Logger()).Log("Message");

public interface ILogger
{
  void Log(string text) => Console.WriteLine(Prefix + text);
  static string Prefix = "File Log: - ";
}

public class Logger:ILogger
{
}