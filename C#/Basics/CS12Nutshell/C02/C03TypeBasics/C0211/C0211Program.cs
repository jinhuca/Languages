// Reference Types
// A reference type has two parts: an object and the reference to that object.
Point p1 = new Point();
p1.X = 7;
Point p2 = p1;              // Copies p1 *reference*
Console.WriteLine(p1.X);    // 7
Console.WriteLine(p2.X);    // 7

p1.X = 9;                   // Change P1.X
Console.WriteLine(p1.X);    // 9
Console.WriteLine(p2.X);    // 9

public class Point { public int X, Y; }