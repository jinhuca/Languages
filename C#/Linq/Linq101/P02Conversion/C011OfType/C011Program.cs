// OfType: Filters elements of specified type in a collection.
object[] objects_ = { "Thomas", 31, 5.02, null, "Joey" };
var result_ = objects_.OfType<string>();

Console.WriteLine("Objects being of type string have the values:");
foreach (var str in result_) 
  Console.WriteLine(str);
