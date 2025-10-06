// Calculate prime numbers with ordered output.

IEnumerable<int> numbers = Enumerable.Range(3, 1000000 - 3);

var parallelQuery =
  from n in numbers.AsParallel().AsOrdered()
  where Enumerable.Range(2, (int)Math.Sqrt(n)).All(i => n % i > 0)
  select n;

int[] primes = parallelQuery.ToArray();

foreach (var num in primes.Take(100))
{
  Console.WriteLine(num);
}