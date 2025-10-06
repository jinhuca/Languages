using System.Reactive.Linq;
using System.Runtime;
using Helpers;

namespace P261ReactToErrors;

internal class P261Program
{
  static void Main(string[] args)
  {
    //ReactOnErrors();
    //CatchErrors();
    CatchAllExceptions();
  }

  static void ReactOnErrors()
  {
    IObservable<WeatherSimulation> weatherSimulationResults =
      Observable.Throw<WeatherSimulation>(new OutOfMemoryException());

    weatherSimulationResults
      .Subscribe(
        _ => { },
        e =>
        {
          if(e is OutOfMemoryException)
          {
            //a last attampt to free some memory
            GCSettings.LargeObjectHeapCompactionMode =
              GCLargeObjectHeapCompactionMode.CompactOnce;
            GC.Collect();
            GC.WaitForPendingFinalizers();

            Console.WriteLine("GC Done");
          }
        });
  }

  static void CatchErrors()
  {
    IObservable<WeatherSimulation> weatherSimulationResults =
      Observable.Throw<WeatherSimulation>(new OutOfMemoryException());
    weatherSimulationResults
      .Catch((OutOfMemoryException ex) =>
      {
        Console.WriteLine("handling OOM exception");
        return Observable.Empty<WeatherSimulation>();
      })
      .SubscribeConsole("Catch (source throws), and terminate observation.");
    Console.ReadLine();
  }

  static void CatchAllExceptions()
  {
    IObservable<WeatherSimulation> weatherSimulationResults =
      Observable.Throw<WeatherSimulation>(new OutOfMemoryException());
    weatherSimulationResults
      .Catch(Observable.Empty<WeatherSimulation>())
      .SubscribeConsole("Catch (all exception types)");
    Console.ReadLine();
  }
}