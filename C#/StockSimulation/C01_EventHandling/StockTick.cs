using System;
using System.Collections.Generic;
using System.Text;

namespace C01_EventHandling;

internal class StockTick {
  public event EventHandler<StockInfo> StockPriceChanged = delegate { };
  public void Notify(StockInfo e) {
    StockPriceChanged(this, e);
  }
}