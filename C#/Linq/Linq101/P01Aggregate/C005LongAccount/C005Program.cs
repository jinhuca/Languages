// Use LongCount() when you expect the result to be greater than Int32.MaxValue

var largeArr_ = Enumerable.Range(0, Int32.MaxValue).Concat(Enumerable.Range(0,5));
Int64 result_=largeArr_.LongCount();
Console.WriteLine($"Counting largeArr elements: {result_}");