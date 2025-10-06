using System.Diagnostics;

namespace C0201;

internal class C0201Program
{
  static void DisplayProcesses()
  {
    List<string> processes_ = new List<string>();
    foreach(var process in Process.GetProcesses())
    {
      processes_.Add(process.ProcessName);
    }
    ObjectDumper.Write(processes_);
  }

  static void Main(string[] args)
  {
    DisplayProcesses();
  }
}