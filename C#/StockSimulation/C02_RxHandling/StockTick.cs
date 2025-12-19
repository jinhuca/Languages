using System;
using System.Collections.Generic;
using System.Text;

namespace C02_RxHandling;

internal class StockTick {
  public event EventHandler<Stock> StockPriceChanged = delegate { };
  public void Notify(Stock e) {
    StockPriceChanged(this, e);
  }
}