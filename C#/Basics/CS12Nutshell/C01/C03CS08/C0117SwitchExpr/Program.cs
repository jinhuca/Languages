Console.WriteLine("Enter a integer between 1 and 13 inclusively: ");
var cardNumber = int.Parse(Console.ReadLine() ?? string.Empty);

string cardName = cardNumber switch
{
  13=>"King",
  12=>"Queen",
  11=>"Jack",
  _=> "Pip card"    // equivalent to 'default'
};

Console.WriteLine(cardName);