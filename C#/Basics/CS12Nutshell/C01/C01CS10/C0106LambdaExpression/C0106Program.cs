using System.ComponentModel;
using System.Linq.Expressions;
using static System.Console;

var greeter = () => WriteLine("Hello, world.");
greeter();

var square = (int x) => x * x;
WriteLine(square(5));

var sqr = int (int x) => x * x;
WriteLine(sqr(6));

M1(() => "test");
M2(() => "test");
M3(() => "test");

void M1(object x) { WriteLine(x); }
void M2(Delegate x) { }
void M3(Expression x) { WriteLine(x); }

Action a = [Description("test")] () => { };