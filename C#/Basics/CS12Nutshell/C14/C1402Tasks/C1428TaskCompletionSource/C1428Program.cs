// TaskCompletionSource - Our own Run Method
Task<int> task = Run(() => { Thread.Sleep(5000); return 42; });
Console.WriteLine(task.Result);

Task<TResult> Run<TResult>(Func<TResult> function)
{
  var tcs = new TaskCompletionSource<TResult>();
  new Thread(() =>
  {
    try { tcs.SetResult(function()); }
    catch (Exception ex) { tcs.SetException(ex); }
  }).Start();
  return tcs.Task;
}
