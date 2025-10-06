// 	SingleOrDefault: Retrieves only element in a collection, or default value if collection is empty.

using static System.Console;

string[] names1_ = { "Peter" };
string[] names3_ = { "Peter", "Joe", "Wilma" };
string[] empty_ = { };

var result1_ = names1_.SingleOrDefault();

var resultEmpty_ = empty_.SingleOrDefault();

WriteLine("The only name in the array is:");
WriteLine(result1_);

WriteLine("As array is empty, SingleOrDefault yields null:");
WriteLine(resultEmpty_ == null);

try
{
  // This will throw an exception as well because array contains more than one element
  var result3_ = names3_.SingleOrDefault();
  WriteLine(result3_);
}
catch(Exception e_)
{
  WriteLine(e_.Message);
}