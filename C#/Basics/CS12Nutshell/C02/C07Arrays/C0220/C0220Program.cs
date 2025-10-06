using static System.Console;

// Arrays
{
  // An array represents a fixed number of elements of a particular type.
  char[] vowels = new char[5]; // Declare an array of 5 characters

  // Square brackets also index the array, accessing a particular element by position:
  vowels[0] = 'a';
  vowels[1] = 'e';
  vowels[2] = 'i';
  vowels[3] = 'o';
  vowels[4] = 'u';
  WriteLine(vowels[1]); // e

  // Array indexes start at 0. We can use a for loop statement to iterate through each element in the array.
  // The for loop in this example cycles the integer i from 0 to 4:
  for (int i = 0; i < vowels.Length; i++)
  {
    WriteLine(vowels[i]);
  }

  // An array initialization expression:
  char[] easy = { 'a', 'e', 'i', 'o', 'u' };
  WriteLine(easy);
}

// Default Element Initialization
{
  // Creating an array always pre-initializes the elements with default values.
  // For int, this is 0:
  int[] a = new int[1000];
  WriteLine(a[123]);
}