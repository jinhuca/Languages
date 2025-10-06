// Storage Overhead

Main();

unsafe static void Main()
{
  Console.WriteLine(sizeof(Point));
  Console.WriteLine(sizeof(A));
}

struct Point
{
  private int x;    // 4 bytes
  private int y;    // 4 bytes
}

// However, the CLR requires that fields are offset within the type at an address
// that's a multiple of their size:
struct A
{
  private byte b;   // 1 byte
  private long l;   // 8 bytes
}