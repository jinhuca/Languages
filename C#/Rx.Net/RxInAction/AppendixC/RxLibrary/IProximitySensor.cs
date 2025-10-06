using System.Reactive;

namespace RxLibrary;

public interface IProximitySensor
{
  IObservable<Unit> Readings { get; }
}