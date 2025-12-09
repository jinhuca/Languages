var primes = new List<int>() { 1, 2, 3, 5, 7, 11, 13, 17, 19 };
var query = from num in primes
            where num < 7
            select num;
foreach (var prime in query) {
  Console.WriteLine(prime);
}