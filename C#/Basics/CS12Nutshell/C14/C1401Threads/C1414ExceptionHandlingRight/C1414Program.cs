new Thread(Go).Start();

void Go()
{
  try
  {
    throw null;         // The NullReferenceException will get caught below.
  }
  catch (Exception ex)
  {
    Console.WriteLine("Caught!");
  }
}