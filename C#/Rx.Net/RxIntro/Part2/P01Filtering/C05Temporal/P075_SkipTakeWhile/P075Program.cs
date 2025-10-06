using System.Reactive.Linq;
using System.Reactive.Subjects;
using static System.Console;

var subject1_ = new Subject<int>();
subject1_
  .SkipWhile(i => i < 4)
  .Subscribe(WriteLine, () => WriteLine("Completed"));

subject1_.OnNext(1);
subject1_.OnNext(2);
subject1_.OnNext(3);
subject1_.OnNext(4);
subject1_.OnNext(3);
subject1_.OnNext(2);
subject1_.OnNext(1);
subject1_.OnNext(0);
subject1_.OnCompleted();

var subject2_ = new Subject<int>();
subject2_
  .TakeWhile(i => i < 4)
  .Subscribe(WriteLine, () => WriteLine("Completed"));

subject2_.OnNext(1);
subject2_.OnNext(2);
subject2_.OnNext(3);
subject2_.OnNext(4);
subject2_.OnNext(3);
subject2_.OnNext(2);
subject2_.OnNext(1);
subject2_.OnNext(0);
subject2_.OnCompleted();
