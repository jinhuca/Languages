// Cast: Casts a collection to a specified type.
List<object> vegetables_ = ["Cucumber", "Tomato", "Broccoli"];

// The source we're casting from must contain only elements of the same type.
var result_ = vegetables_.Cast<string>();

Console.WriteLine("List of vegetables casted to a simple string array:");
foreach(var vegetable in result_)
  Console.WriteLine(vegetable);
