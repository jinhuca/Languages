var list = new List<int> { 1, 2, 3, 5, 7, 11, 13 };
var enumeraable = list.Where(n => n < 6);
foreach (var item in enumeraable)
  Console.WriteLine(item);
