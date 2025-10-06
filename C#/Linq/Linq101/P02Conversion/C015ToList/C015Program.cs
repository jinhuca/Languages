// ToList: Converts collection into a List.

string[] names_ = { "Brenda", "Carl", "Finn"};
var result_ = names_.ToList();

Console.WriteLine($"names is of type: {names_.GetType().Name}");
Console.WriteLine($"names is of type: {result_.GetType().Name}");
