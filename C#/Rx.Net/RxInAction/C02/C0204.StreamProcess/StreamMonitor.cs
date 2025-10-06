using System;
using System.Collections.Generic;
using System.Linq;
using System.Reactive.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C0204.StreamProcess;

public class StreamMonitor
{
  private readonly IDisposable _subscription;
  public IObservable<DrasticChange> DrasticChanges { get; }

  public StreamMonitor(IObserver<StockTick> observer)
  {
    const decimal maxChangeRatio = 0.1m;
    var service_ = new StockService();
    
    service_.Run(observer);

    IObservable<StockTick> ticks_ = service_.StockObservable;


    //IObservable<DrasticChange> drasticChanges_ =
    //  from tick in 
  }
}