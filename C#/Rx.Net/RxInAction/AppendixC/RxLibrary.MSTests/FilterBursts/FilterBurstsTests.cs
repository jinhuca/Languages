﻿using Microsoft.Reactive.Testing;
using System.Reactive.Linq;

namespace RxLibrary.MSTests.FilterBursts;

public class FilterBurstsTests : ReactiveTest
{
  [TestMethod]
  public void FilterBursts_SeuquenceOf10AndBurstSize5_TwoEmissions()
  {
    var seqeucneSize = 10;
    var burstSize = 5;
    var expected = new[] { 0, 5 };
    var xs = Observable.Range(0, seqeucneSize);

    xs.FilterBursts(burstSize)
      .AssertEqual(expected.ToObservable());
  }

  [DataRow(1, 1, new[] { 0 })]
  [DataRow(5, 1, new[] { 0 })]
  [DataRow(1, 5, new[] { 0, 1, 2, 3, 4 })]
  [DataRow(5, 5, new[] { 0 })]
  [DataRow(5, 8, new[] { 0, 5 })]
  public void FilterBursts(int burstSize, int sequenceSize, int[] expected)
  {
    var observable = Observable.Range(0, sequenceSize);
    observable.FilterBursts(burstSize)
      .AssertEqual(expected.ToObservable());
  }

  [TestMethod]
  public void FilterBursts_TwoBurstAndGapInEachBurst_FirstInEachBurstEmitted()
  {
    var scheduler = new TestScheduler();
    var xs = scheduler.CreateHotObservable(
      OnNext(250, 1),
      OnNext(260, 2),
      OnNext(270, 3),
      OnNext(400, -1),
      OnNext(401, -2),
      OnNext(405, -3),
      OnCompleted<int>(500)
    );

    var res = scheduler.Start(() => xs.FilterBursts(3));

    res.Messages.AssertEqual(
      OnNext(250, 1),
      OnNext(400, -1),
      OnCompleted<int>(500));

    xs.Subscriptions.AssertEqual(
      Subscribe(Subscribed, 500));
  }

  [TestMethod]
  public void FilterBursts_TwoBurstAndGapInEachBurst_FirstInEachBurstEmitted_WithTestableObserver()
  {
    var scheduler = new TestScheduler();

    // Creating an observable that will emit two bursts of values 1-to-3 and (-1)-to-(-3)
    var xs = scheduler.CreateHotObservable(
      OnNext(250, 1),
      OnNext(275, 2),
      OnNext(300, 3),
      OnNext(400, -1),
      OnNext(401, -2),
      OnNext(405, -3),
      OnCompleted<int>(500)
    );

    // Creating a TestableObserver that is capable of recording its observations
    var testableObserver = scheduler.CreateObserver<int>();

    // Act - This is the code we want to test. 
    //Since we havent started the scheduler yet, its clock time is 0 (i.e. subscription time is 0) 
    xs.FilterBursts(3)
      .Subscribe(testableObserver);

    // Starting the Scheduler so the TestableObservable will starts emitting
    scheduler.Start();

    // Asserting the results
    testableObserver.Messages.AssertEqual(
      OnNext(250, 1),
      OnNext(400, -1),
      OnCompleted<int>(500));

    xs.Subscriptions.AssertEqual(
      Subscribe(0, 500));
  }
}