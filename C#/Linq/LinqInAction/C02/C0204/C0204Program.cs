using System.Diagnostics;

namespace C0204;

internal class C0204Program
{
  class ProcessData
  {
    public Int32 Id { get; set; }
    public Int64 Memory { get; set; }
    public string Name { get; set; }
  }

  static void DisplayProcesses()
  {
    var processes_ = new List<ProcessData>();
    foreach(var process_ in Process.GetProcesses())
    {
      processes_.Add(new ProcessData()
      {
        Id = process_.Id,
        Memory = process_.WorkingSet64,
        Name = process_.ProcessName
      });
    }
    ObjectDumper.Write(processes_);
  }

  static void Main(string[] args)
  {
    DisplayProcesses();
  }
}