// Null
// A reference can be assigned the literal null, indicating that the reference points to nothing.
Point p = null;
Console.WriteLine(p == null);       // True

// The following line generates a runtime error (a NullReferenceException is thrown):
Console.WriteLine(p.X);

public class Point { public int X, Y; }