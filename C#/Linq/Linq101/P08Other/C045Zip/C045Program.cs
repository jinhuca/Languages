// Zip: Processes two collections in parallel with func instance, and combines result
// into a new collection.

int[] numbers1_ = { 1, 2, 3 };
int[] numbers2_ = { 10, 11, 12 };

var result_ = numbers1_.Zip(numbers2_, (a, b) => a * b);

Console.WriteLine("Using Zip to combine two arrays into one (1*10, 2*11, 3*12):");
foreach(var number_ in result_)
  Console.WriteLine(number_);