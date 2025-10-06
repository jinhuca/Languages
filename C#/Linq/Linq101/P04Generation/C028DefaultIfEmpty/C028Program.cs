// DefaultIfEmpty: If a collection is empty, its default value is returned.
// Default value depends on collection type. A default value may be specified.

using static System.Console;

int[] empty_ = [];
var result_ = empty_.DefaultIfEmpty(5);

WriteLine("result contains one element with a value of 5:");
WriteLine(result_.Count() == 1 && result_.First() == 5);
