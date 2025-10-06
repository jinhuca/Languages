// Concat: Concatenates (combines) two collections.

using static System.Console;

int[] numbers1_ = [1, 2, 3];
int[] numbers2_ = [4, 5, 6];

var result_ = numbers1_.Concat(numbers2_);
WriteLine("Concatenating numbers1_ and numbers2_ gives:");
foreach(var number_ in result_)
  WriteLine(number_);