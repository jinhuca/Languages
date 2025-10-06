// Real Number Rounding Errors
// Unlike decimal, float and double can cannot precisely represent numbers with a base-10
// fractional component:
{
  float x = 0.1f;  // Not quite 0.1
  Console.WriteLine(x + x + x + x + x + x + x + x + x + x);    // 1.0000001
}
{
  decimal y = 0.1m;  // Exactly 0.1
  Console.WriteLine(y + y + y + y + y + y + y + y + y + y);    // 1.0
}

// Neither double nor decimal can precisely represent a fractional number whose base 10
// representation is recurring:

decimal m = 1M / 6M;              // 0.1666666666666666666666666667M
double d = 1.0 / 6.0;             // 0.16666666666666666

Console.WriteLine($"{nameof(m)} = {m}");
Console.WriteLine($"{nameof(d)} = {d}");

// This leads to accumulated rounding errors:
decimal notQuiteWholeM = m + m + m + m + m + m;  // 1.0000000000000000000000000002M
double notQuiteWholeD = d + d + d + d + d + d;  // 0.99999999999999989

// which breaks equality and comparison operations:
Console.WriteLine(notQuiteWholeM == 1M);   // False
Console.WriteLine(notQuiteWholeD < 1.0);   // True