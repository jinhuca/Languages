// Union: Combines two collections and removes duplicate elements.
using static System.Console;

int[] numbers1_ = [1, 2, 3];
int[] numbers2_ = [3, 4, 5];

var result_ = numbers1_.Union(numbers2_);

WriteLine("Union creates a single sequence and eliminates the duplicates:");
foreach(int number_ in result_)
  WriteLine(number_);
