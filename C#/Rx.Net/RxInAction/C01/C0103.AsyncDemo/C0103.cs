using System.Diagnostics;

var taskA = LongDiskWriteAsync();
var taskB = LongWebRequestAsync();
var taskC = LongDatabaseQueryAsync();

//taskA.Wait();
//taskB.Wait();
//taskC.Wait();
Task.WaitAll(taskA, taskB, taskC);

async Task LongDatabaseQueryAsync()
{
  Console.WriteLine($"Start database query at thread# {Environment.CurrentManagedThreadId}");
  await Task.Delay(3000);
  Console.WriteLine($"Database query finished at thread# {Environment.CurrentManagedThreadId}");
}

async Task LongWebRequestAsync()
{
  Console.WriteLine($"Start web request at thread# {Environment.CurrentManagedThreadId}");
  await Task.Delay(2000);
  Console.WriteLine($"Web request finished at thread# {Environment.CurrentManagedThreadId}");
}

async Task LongDiskWriteAsync()
{
  Console.WriteLine($"Start disk writing at thread# {Environment.CurrentManagedThreadId}");
  await Task.Delay(6000);
  Console.WriteLine($"Disk writing finished at thread# {Environment.CurrentManagedThreadId}");
}