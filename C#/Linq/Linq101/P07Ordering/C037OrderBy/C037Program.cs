// OrderBy: Sorts a collection in ascending order.

using static System.Console;

Car[] cars =
{
  new() { Name = "Super Car", HorsePower = 215 },
  new() { Name = "Economy Car", HorsePower = 75 },
  new() { Name = "Family Car", HorsePower = 145 },
};

var result = cars.OrderBy(c => c.HorsePower);

WriteLine("Ordered list of cars by horsepower:");
foreach(Car car in result)
  WriteLine($"{car.Name}: {car.HorsePower} horses");

class Car
{
  public string Name { get; set; }
  public int HorsePower { get; set; }
}