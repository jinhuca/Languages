await A();

async Task A()
{
  await B();
}

async Task B()
{
  for (int i = 0; i < 5; i++)
    await C().ConfigureAwait(false);
}

async Task C()
{
  await Task.Delay(1000);
  Console.WriteLine("Done.");
};