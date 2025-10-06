using static System.Console;

// Range: Generates sequence of numeric values.

var result_ = Enumerable.Range(0, 10);
WriteLine("Counting from 0 to 9:");
foreach (var number in result_) 
  WriteLine(number);