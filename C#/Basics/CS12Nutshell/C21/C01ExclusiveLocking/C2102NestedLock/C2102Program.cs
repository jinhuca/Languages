namespace C2102NestedLock;

internal class C2102Program
{
  static object locker = new object();

  static void Main(string[] args)
  {
    AnotherMethod();
    // We still have the lock - because locks are reentrant.
  }

  static void AnotherMethod()
  {
    lock(locker){
      Console.WriteLine("Another method.");
    }
  }
}