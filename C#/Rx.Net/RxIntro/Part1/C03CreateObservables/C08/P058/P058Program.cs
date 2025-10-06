using System.Reactive.Subjects;
using static System.Console;

Subject<int> s_ = new();
s_.Subscribe(x => WriteLine($"sub1: {x}"));
s_.Subscribe(x => WriteLine($"Sub2: {x}"));

s_.OnNext(1);
s_.OnNext(2);
s_.OnNext(3);

ReadKey();