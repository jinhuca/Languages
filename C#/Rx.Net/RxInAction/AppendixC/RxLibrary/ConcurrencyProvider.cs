using System;
using System.Collections.Generic;
using System.Linq;
using System.Reactive.Concurrency;
using System.Text;
using System.Threading.Tasks;

namespace RxLibrary
{
  class ConcurrencyProvider : IConcurrencyProvider
  {
    public ConcurrencyProvider()
    {
      TimeBasedOperations = DefaultScheduler.Instance;
      Task = TaskPoolScheduler.Default;
      Thread = NewThreadScheduler.Default;

#if HAS_DISPATCHER
            Dispatcher=DispatcherScheduler.Current;
#else
      //workaround to whenever there's no dispatcher
      Dispatcher = CurrentThreadScheduler.Instance;
#endif
    }

    public IScheduler TimeBasedOperations { get; }
    public IScheduler Task { get; }
    public IScheduler Thread { get; }
    public IScheduler Dispatcher { get; }
  }
}
