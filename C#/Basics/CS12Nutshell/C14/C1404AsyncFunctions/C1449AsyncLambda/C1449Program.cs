// Named asynchronous method:
async Task NamedMethod()
{
  await Task.Delay(1000);
  Console.WriteLine("Foo");
}

// Unnamed asynchronous method:
Func<Task> unnamed = async () =>
{
  await Task.Delay(1000);
  Console.WriteLine("Bar");
};

// We can call the two in the same way:
await NamedMethod();
await unnamed();