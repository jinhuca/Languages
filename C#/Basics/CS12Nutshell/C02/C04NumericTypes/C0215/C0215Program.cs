// Numeric Types

{
  // The signed integral types are sbyte, short, int, long:
  int i = -1;
  Console.WriteLine(i);

  // The unsigned integral types are byte, ushort, uint and ulong:
  byte b = 255;
  Console.WriteLine(b);

  // The real types are float, double, and decimal:
  double d = 1.23;
  Console.WriteLine(d);
}

// Numeric Literals
{
  // Integral literals can use decimal or hexadecimal notation; hexadecimal is denoted with the 0x prefix:
  int x = 127;
  long y = 0x7F;

  //From C# 7, you can insert an underscore anywhere inside a numeric literal to make it more readable:
  int million = 1_000_000;

  //C# 7 also lets you specify numbers in binary with the 0b prefix:
  var b = 0b1010_1011_1100_1101_1110_1111;

  // Real literals can use decimal and/or exponential notation:
  double d = 1.5;
  double doubleMillion = 1E06;

  // Numeric literal type inference:
  Console.WriteLine(1.0.GetType());       // Double  (double)
  Console.WriteLine(1E06.GetType());       // Double  (double)
  Console.WriteLine(1.GetType());       // Int32   (int)
  Console.WriteLine(0xF0000000.GetType());       // UInt32  (uint)
  Console.WriteLine(0x100000000.GetType());       // Int64   (long)
}

// Numeric Suffixes
{
  // Numeric literals can be suffixed with a character to indicate their type:
  //  F = float
  //  D = double
  //  M = decimal
  //  U = uint
  //  L = long
  //  UL = ulong

  long i = 5;     // No suffix needed: implicit lossless conversion from int literal to long
  double x = 4.0; // D is redundant.

  // The F and M suffixes are the most useful:
  float f = 4.5F;     // will not compile without the F suffix
  decimal d = -1.23M; // will not compile without the M suffix
}

// Numeric Conversions
{
  // Integral conversions are implicit when the destination type can represent every possible value
  // of the source type. Otherwise, an explicit conversion is required:
  int x = 12345;        // int is a 32-bit integral
  long y = x;           // Implicit conversion to 64-bit integral
  short z = (short)x;   // Explicit conversion to 16-bit integral

  // All integral types may be implicit converted to all floating-point numbers:
  int i = 1;
  float f = i;

  // The reverse conversion must be explicit:
  int iExplicit = (int)f;

  // Implicit converting a large integral type to a floating-point type preserves magnitude but may
  // occasionally lose precision:
  int i1 = 100_000_001;
  Console.WriteLine(i1);
  float f1 = i1;          // Magnitude preserved, precision lost
  Console.WriteLine(f1);
  int i2 = (int)f1;       // 100_000_000
  Console.WriteLine(i2);
}

// Increment and Decrement Operators
{
  // The increment and decrement operator (++, --) increment and decrement numeric types by 1.
  // The operator can either precede or follow the variable, depending on whether you want the 
  // value before or after the increment / decrement:
  int x = 0, y = 0;
  Console.WriteLine(x++);
  Console.WriteLine(++y);
}

// Integral Division
{
  // Integral division truncate remainders:
  int a = 2 / 3;      // 0
  // Division by zero is an error:
  int b = 0;
  try
  {
    int c = 5 / b; // throws DivisionByZeroException
  }
  catch (DivideByZeroException e)
  {
    Console.WriteLine(e.Message);
  }
}

// Integral Overflow
{
  // By default, integral arithmetic operations overflow silently:
  int a = int.MinValue;
  a--;
  Console.WriteLine(a == int.MaxValue);   // True
}

// Overflow Checking
{
  // You can add the checked keyword to force overflow checking:
  int a = 1000000;
  int b = 1000000;

  // The following code throws OverflowExceptions:
  int c = checked(a * b);     // Checks just the expressions.

  // Checks all expressions in statement block:
  checked
  {
    int c2 = a * b;
    Console.WriteLine(c2);
  }
}

// Overflow Checking with Constant Expressions
{
  // Compile-time overflows are special in that they're checked by default:
  // int x = int.MaxValue + 1;     // Compile-time error

  // You have to use unchecked to disable this:
  int y = unchecked(int.MaxValue + 1);    // No errors
}

// 8- and 16-bit literals
{
  // The 8- and 16-bit integral types are byte, sbyte, short, and ushort. These types lack their
  // own arithmetic operators, so C# implicitly converts them to larger types as required.
  // This can cause a compile-time error when trying to assign the result back to a small integral type:
  short x = 1, y = 1;
  //short z = x + y;          // Compile-time error

  // x and y are implicitly converted to int so that the addition can be performed.
  // To make this compile, we must add an explicit cast:
  short z = (short)(x + y);   // OK
} 