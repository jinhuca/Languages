var triple = (int x) => x * 3;
var range = Enumerable.Range(1, 3);
var triples = range.Select(triple);
triples.ToList().ForEach(Console.WriteLine);