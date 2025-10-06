namespace E01;

public class E01Program {
  static void Main()   {
    var publisher = new Publisher(88);
    var subscriber = new Subscriber();
    publisher.PriceChanged += subscriber.HandlePriceChange;
    publisher.Price = 99;
  }
}

public delegate void PriceChangedEventHandler(object sender, int newValue);

public class Publisher(int price) {
  public event PriceChangedEventHandler PriceChanged;

  protected virtual void OnPriceChanged() {
    PriceChanged(this, Price);
  }

  private int _price = price;
  public int Price { 
    get => _price;
    set {
      if (_price != value) {
        _price = value;
        OnPriceChanged();
      }
    }
  }
}

public class Subscriber {
  public void HandlePriceChange(object sender, int newValue) {
    Console.WriteLine($"The price has been changed to {newValue}");
  }
}