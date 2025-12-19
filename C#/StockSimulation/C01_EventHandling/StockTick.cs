using System;
using System.Collections.Generic;
using System.Text;

namespace C01_EventHandling;

internal class StockTick {
  public event EventHandler<Stock> StockPriceChanged = delegate { };
  public void Notify(Stock e) {
    StockPriceChanged(this, e);
  }
}