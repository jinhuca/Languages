var tcs = new TaskCompletionSource<int>();
new Thread(() => { Thread.Sleep(1000); tcs.SetResult(42); }).Start();
Task<int> task = tcs.Task;          // Our "slave" task.
Console.WriteLine(task.Result);     // 42
