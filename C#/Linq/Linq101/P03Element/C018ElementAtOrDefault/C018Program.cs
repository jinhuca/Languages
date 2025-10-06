// ElementAtOrDefault: Retrieves element from a collection at specified (Zero-based) index,
// but gets default value if out-of-range.

using static System.Console;

string[] colors_ = { "Red", "Green", "Blue" };
var resultIndex1_ = colors_.ElementAtOrDefault(1);
var resultIndex10_ = colors_.ElementAtOrDefault(10);

WriteLine($"Element at index 1 in the array contains: {resultIndex1_}");
WriteLine($"Element at index 10 in the array does not exist: {resultIndex10_}");
WriteLine(resultIndex10_ == null);
