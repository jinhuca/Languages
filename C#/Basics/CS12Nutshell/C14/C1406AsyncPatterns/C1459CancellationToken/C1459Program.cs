Main();
Console.ReadLine();

async void Main()
{
  var cancelSource = new CancellationTokenSource();
  // Tell it to cancel in two seconds.
  await Task.Delay(2000).ContinueWith(ant => cancelSource.Cancel());
  await Foo(cancelSource.Token);
}

async Task Foo(CancellationToken cancellationToken)
{
  for(int i = 0; i < 10; i++)
  {
    Console.WriteLine(i);
    await Task.Delay(3000);
    cancellationToken.ThrowIfCancellationRequested();
  }
}