// Empty: Generates an empty collection (with no elements).

var empty_ = Enumerable.Empty<string>();

// To make sequence into an array use empty.ToArray()
Console.WriteLine($"Sequence is empty: {empty_.Count() == 0}");