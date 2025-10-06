try
{
  new Thread(Go).Start();
}
catch (Exception ex)
{
  Console.WriteLine(ex.ToString());     // We'll never get here!
}

static void Go() { throw null; }        // Throws a NullReferenceException