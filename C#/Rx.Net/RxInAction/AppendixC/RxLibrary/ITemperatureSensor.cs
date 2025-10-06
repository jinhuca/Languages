namespace RxLibrary;

public interface ITemperatureSensor
{
  IObservable<double> Readings { get; }
}