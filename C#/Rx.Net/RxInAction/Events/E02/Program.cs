namespace E02;

internal class Program
{
  static void Main(string[] args)
  {
    var publisher = new Publisher(90);
    var subscriber = new Subscriber();
    publisher.PriceChanged += delegate(object? sender, int price) {
      Console.WriteLine($"The price has been changed to {price}");
    };
    publisher.PriceChanged += (sender, price) => {
      Console.WriteLine($"The price has been changed to {price}");
    };
    publisher.Price = 92;
  }
}

public class Publisher(int price) {
  public event EventHandler<int> PriceChanged;
  protected virtual void OnPriceChanged() => PriceChanged(this, Price);

  private int _price = price;
  public int Price
  {
    get => _price;
    set {
      if(_price != value)       {
        _price = value;
        OnPriceChanged();
      }
    }
  }
}

public class Subscriber
{
  public void HandlePriceChange(object sender, int newValue)
  {
    Console.WriteLine($"The price has been changed to {newValue}");
  }
}