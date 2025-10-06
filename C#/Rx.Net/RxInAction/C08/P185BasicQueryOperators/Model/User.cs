namespace P185BasicQueryOperators.Model;

internal class User(string name, string id)
{
  public string Name { get; set; } = name;
  public string Id { get; set; } = id;

  public override string ToString() => $"Id: {Id} Name: {Name}";
}