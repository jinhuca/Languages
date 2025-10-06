// Aggregate: Performs a specified operation to each element in a collection,
// while carrying the result forward.

var numbers_ = new[] { 1, 2, 3, 4, 5 };
var result_ = numbers_.Aggregate(10, (a, b) => a * b);
Console.WriteLine(result_);
