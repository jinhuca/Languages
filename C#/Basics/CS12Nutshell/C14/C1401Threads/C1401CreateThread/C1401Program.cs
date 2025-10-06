Thread t = new Thread(n =>
{
  var x = 100;
  WriteY(x);
});        // Kick off a new thread
t.Name = "Test Thread";
t.Start();                            // running WriteY()

// Simultaneously, do something on the main thread.
for(int i = 0; i < 100; i++)
{
  Console.Write("x");
}

void WriteY(int n)
{
  Console.WriteLine($"Name: {Thread.CurrentThread.Name}");
  for(int i = 0; i < n; i++)
  {
    Console.Write("y");
  }
}