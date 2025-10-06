using C0102.ShoppyExample.Domain;
using System.ComponentModel;
using System.Reactive.Linq;
using static System.Console;

namespace C0102.ShoppyExample;

public class Shoppy
{
  public void TestShoppy()
  {
    StoreIconExample();
    ConnectivityExample();
  }

  [Description("Shows how you can combine multiple observables")]
  private static void StoreIconExample()
  {
    const double minIconSize = 20;
    const double maxIconSize = 32;

    IObservable<Position> myLocation = CreateDummyLocations();
    Store[] stores = CreateDummyStores();

    var storeLocation = stores
      .ToObservable()
      .SelectMany(store => myLocation, (store, currentLocation) => new { store, currentLocation });

    var iconSize = from store in stores.ToObservable()
      from currentLocation in myLocation
      let dist = Position.Distance(store.Location, currentLocation)
      where dist < 5
      let calcSize = Math.Round((5 / dist) * minIconSize, 0)
      let sizeOrMax = Math.Round(Math.Min(calcSize, maxIconSize), 0)
      let sizeOrMin = Math.Round(Math.Max(sizeOrMax, minIconSize), 0)
      select new
      {
        store.Name,
        StoreX = store.Location.X,
        StoreY = store.Location.Y,
        MeX = currentLocation.X,
        MeY = currentLocation.Y,
        dist,
        calcSize,
        sizeOrMin,
        sizeOrMax
      };

    iconSize.Subscribe(WriteLine);
  }

  [Description("Shows how asynchrnous code execution get be part of the observable pipline")]
  private void ConnectivityExample()
  {
    IObservable<Connectivity> myConnectivity = Observable.Empty<Connectivity>();
    IObservable<IEnumerable<Discount>> newDiscounts = myConnectivity
      .Where(connectivity => connectivity == Connectivity.Online)
      .SelectMany(connectivity => GetDiscounts());

    newDiscounts.Subscribe(RefreshView);
  }

  #region Helper Methods
  private static IObservable<Position> CreateDummyLocations()
  {
    return Observable.Range(1, 50).Select(i => new Position { X = i, Y = i * 2 });
  }

  private static Store[] CreateDummyStores()
  {
    return new[]
    {
      new Store
      {
        Location = new Position { X = 10, Y = 15 },
        Name = "ShopA"
      },
      new Store
      {
        Location = new Position { X = 2, Y = 3 },
        Name = "ShopB"
      },
      new Store
      {
        Location = new Position { X = 7, Y = 12 },
        Name = "ShopC"
      }
    };
  }

  private void RefreshView(IEnumerable<Discount> discounts)
  {
    throw new NotImplementedException();
  }

  // Sends request to the server and receives the collection of discounts
  private Task<IEnumerable<Discount>> GetDiscounts()
    => Task.FromResult(Enumerable.Empty<Discount>());

  // Sends request to the server and receives the collection of discounts
  private Task<IEnumerable<Discount>> GetDiscounts(Position currentLocation)
    => Task.FromResult(Enumerable.Empty<Discount>());

  #endregion
}