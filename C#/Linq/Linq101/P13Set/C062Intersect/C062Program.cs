// 	Intersect: Takes only the elements that are shared between two collections.

using static System.Console;

int[] numbers1_ = [1, 2, 3];
int[] numbers2_ = [3, 4, 5];

var result_ = numbers1_.Intersect(numbers2_);

WriteLine("Intersect creates a single sequence with only the duplicates:");
foreach(int number_ in result_)
  WriteLine(number_);
