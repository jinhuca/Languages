using static System.Console;

// Character literals
{
  // C#'s char type represents a Unicode character and occupies two bytes.
  char c = 'A';         // Simple character

  // Escape sequences express characters that cannot be expressed or interpreted literally.
  // An escape sequence is a backslash followed by a character with a special meaning:
  char newLine = '\n';
  char backSlash = '\\';
  WriteLine(c);
  WriteLine(backSlash + newLine.ToString() + backSlash);
}

// Character conversions
{
  // An implicit conversion from a char to a numeric type works for the numeric types that can
  // accommodate an unsigned short:
  ushort us = 'a';
  int i = 'z';
  WriteLine(us);
  WriteLine(i);

  // For other numeric types, an explicit conversion is required
  short s = (short)'a';
  WriteLine(s);
}

// String literals
{
  // A string literal is specified inside double quotes:
  string h = "Heat";

  // string is a reference type, rather than a value type. Its equality operators, however,
  // follow value-type semantics:
  string a = "test";
  string b = "test";
  WriteLine(a == b);      // True

  // The escape sequences that are valid for char literals also work inside strings:
  string t = "Here's a tab:\t";

  // The cost of this is that whenever you need a literal backslash, you must write it twice:
  string a1 = "\\\\server\\fileshare\\helloworld.cs";
  WriteLine(a1);

  // To avoid this problem, C# allows "verbatim string literals" - prefixed with @ symbols:
  string a2 = @"\\server\fileshare\helloworld.cs";
  WriteLine(a2);

  // A verbatim string literal can also span multiple lines:
  string escaped = "First Line\r\nSecond Line";
  string verbatim = @"First Line
Second Line";

  // Assuming your IDE uses CR-LF line separators:
  WriteLine(escaped == verbatim);  // True

  // You can include the double-quote character in a verbatim literal by writing it twice:
  string xml = @"<customer id=""123""></customer>";
  WriteLine(xml);
}

// String concatenation
{
  // The + operator concatenation two strings:
  string s1 = "a" + "b";
  WriteLine(s1);
  // The right-hand operand may be a non-string value, in which case ToString is called on that value:
  string s2 = "a" + 5;        // a5
  WriteLine(s2);
}

// String interpolation
{
  // A string preceded with the $ character is an interpolated string:
  int x = 4;
  WriteLine($"A square has {x} sides");

  string s = $"255 in hex is {byte.MaxValue:X2}";       // X2 - 2-digit Hexadecimal
  WriteLine(s);

  x = 2;
  s = $@"this spans {x} lines";
  WriteLine(s);
}

// String interpolation and constants
{
  // legal from C# 10:
  const string greeting = "Hello";
  const string message = $"{greeting}, world";
  WriteLine(message);
}
