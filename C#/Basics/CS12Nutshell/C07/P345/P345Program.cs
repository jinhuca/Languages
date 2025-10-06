using System.Collections;

string s = "Hello";

// Because string implements IEnumerable, we can call GetEnumerable():
IEnumerator rator = s.GetEnumerator();
while(rator.MoveNext())
{
  char c = (char)rator.Current;
  Console.Write(c + ".");
}

foreach(var c in s)
{
  Console.Write(c + ".");
}