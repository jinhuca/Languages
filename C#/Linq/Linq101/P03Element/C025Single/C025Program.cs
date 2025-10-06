// Single: Retrieves only element in a collection. Throws exception if not exactly one element in collection.
// Note: Single will throw an Exception, if there is not exactly one element in the array.

using static System.Console;

string[] names1_ = ["Peter"];
string[] names3_ = ["Peter", "Joe", "Wilma"];
string[] empty_ = [];

var result1_ = names1_.Single();

WriteLine("The only name in the array is:");
WriteLine(result1_);

try
{
  // This will throw an exception because array contains no elements
  var resultEmpty_ = empty_.Single();
}
catch(Exception e)
{
  WriteLine(e.Message);
}

try
{
  // This will throw an exception as well because array contains more than one element
  var result3_ = names3_.Single();
}
catch(Exception e)
{
  WriteLine(e.Message);
}