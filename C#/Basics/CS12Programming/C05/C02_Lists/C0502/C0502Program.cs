// See https://aka.ms/new-console-template for more information

using static System.Console;

var numbers_ = new List<int>();
numbers_.Add(123);
numbers_.Add(99);
numbers_.Add(42);
WriteLine(numbers_.Count);
WriteLine($"{numbers_[0]}, {numbers_[1]}, {numbers_[2]}");

numbers_[1] += 1;
WriteLine(numbers_[1]);

numbers_.RemoveAt(1);
WriteLine(numbers_.Count);
WriteLine($"{numbers_[0]}, {numbers_[1]}");