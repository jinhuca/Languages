using static System.Console;

new Thread(Go).Start();     // Call Go() on a new thread.
Go();                       // Call Go() on the main thread.

void Go()
{
  for (int cycles = 0; cycles < 5; cycles++)
  {
    Write(cycles);
  }
}