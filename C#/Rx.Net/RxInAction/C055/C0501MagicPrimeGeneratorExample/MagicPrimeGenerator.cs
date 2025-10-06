namespace C0501MagicPrimeGeneratorExample;

internal class MagicPrimeGenerator
{
  // (1) generate IEnumerable as whole
  public IEnumerable<int> GenerateWithoutYieldReturn(int amount)
  {
    var returns = new List<int>();
    for(int i = 0; i < amount; i++)
    {
      returns.Add(GeneratePrime(i));
    }
    return returns.AsEnumerable();
  }

  // (2) generate IEnumerable with yield return
  public IEnumerable<int> GenerateWithYieldReturn(int amount)
  {
    for(int i = 0; i < amount; ++i)
    {
      yield return GeneratePrime(i);
    }
  }

  // (3) generate IEnumerable with dedicated task
  public async Task<IEnumerable<int>> GenerateAsync(int amount)
  {
    var result = new List<int>();
    await Task.Run(
      () => {
        for(int i = 0; i < amount; ++i)
        {
          result.Add(GeneratePrime(i));
        } });
    return result.AsEnumerable();
  }

  private int GeneratePrime(int index)
  {
    Thread.Sleep(1000);

    var firstNumbers = new[] { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, };
    if(index < firstNumbers.Length)
    {
      return firstNumbers[index];
    }

    return firstNumbers.Last();
  }
}