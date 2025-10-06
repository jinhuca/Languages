using System.Diagnostics;

namespace C0203;

internal class C0203Program
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
    foreach (var process_ in Process.GetProcesses())
    {
      var data_ = new ProcessData();
      data_.Id = process_.Id;
      data_.Name = process_.ProcessName;
      data_.Memory = process_.WorkingSet64;
      processes_.Add(data_);
    }
    ObjectDumper.Write(processes_);
  }

  static void Main()
  {
    DisplayProcesses();
  }
}