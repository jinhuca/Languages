// Concat: Concatenates (combines) two collections.

using static System.Console;

string[] vegetables_ = ["Tomato", "Cucumber", "Carrot"];
string[] fruits_ = ["Apples", "Grapes", "Banana"];

var result_ = vegetables_.Concat(fruits_);

WriteLine("Concatenating vegetables and fruits gives:");
foreach(string piece_ in result_)
  WriteLine(piece_);