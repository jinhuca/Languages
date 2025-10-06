using System.Diagnostics;

namespace C0202;

internal class C0202Program
{
  class ProcessData
  {
    public Int32 Id;
    public Int64 Memory;
    public string Name;
  }

  static void DisplayProcesses()
  {
    List<ProcessData> processes_ = new List<ProcessData>();
    foreach(Process process_ in Process.GetProcesses())
    {
      ProcessData data_ = new ProcessData();
      data_.Id = process_.Id;
      data_.Name = process_.ProcessName;
      data_.Memory = process_.WorkingSet64;
      processes_.Add(data_);
    }
    ObjectDumper.Write(processes_);
  }

  static void Main(string[] args)
  {
    DisplayProcesses();
  }
}