using System.Diagnostics;

namespace C0207;

internal class C0207Program
{
  class ProcessData
  {
    public Int32 Id { get; set; }
    public Int64 Memory { get; set; }
    public string Name { get; set; }
  }

  static void DisplayProcesses(Predicate<Process> match)
  {
    var processes_ = new List<ProcessData>();
    foreach (var process_ in Process.GetProcesses())
    {
      if (match(process_))
      {
        processes_.Add(new ProcessData
        {
          Id= process_.Id, 
          Name = process_.ProcessName, 
          Memory = process_.WorkingSet64
        });
      }
    }
    ObjectDumper.Write(processes_);
  }

  static bool Filter(Process process)
  {
    return process.WorkingSet64 >= 20 * 1024 * 1024;
  }

  static void Main()
  {
    DisplayProcesses(Filter);
  }
}