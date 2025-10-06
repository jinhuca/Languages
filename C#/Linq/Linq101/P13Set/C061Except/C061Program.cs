// Except: Removes all elements from one collection which exist in another collection.

int[] numbers1_ = [1, 2, 3];
int[] numbers2_ = [3, 4, 5];

var result_ = numbers1_.Except(numbers2_);

Console.WriteLine("Except creates a single sequence from numbers1 and removes the duplicates found in numbers2:");
foreach(int number_ in result_)
  Console.WriteLine(number_);
