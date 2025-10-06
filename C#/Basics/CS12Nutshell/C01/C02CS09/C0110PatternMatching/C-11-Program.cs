string GetWeightCategory(Decimal bmi) => bmi switch
{
  < 18.5m => "underweight",
  < 25m => "normal",
  < 30m => "overweight",
  _ => "obese"
};

bool IsVowel(char c) => c is 'a' or 'e' or 'i' or 'o' or 'u';
bool IsLetter(char c) => c is >= 'a' and <= 'z' or >= 'A' and <= 'Z';

Console.WriteLine(GetWeightCategory(21m));
Console.WriteLine("'g' is vowel " + IsVowel('g'));
Console.WriteLine("'#' is letter " + IsLetter('#'));
