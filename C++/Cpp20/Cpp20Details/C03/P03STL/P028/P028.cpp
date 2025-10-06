// P028.cpp : local time in various time zones
#include <chrono>
import std;
using namespace std::chrono;

int main()
{
  auto time = floor<milliseconds>(system_clock::now());
  auto localTime = zoned_time<milliseconds>(current_zone(), time);
  auto berlinTime = zoned_time<milliseconds>("Europe/Berlin", time);
  auto newYorkTime = zoned_time<milliseconds>("America/New_York", time);
  auto tokyoTime = zoned_time<milliseconds>("Asia/Tokyo", time);

  std::cout << "System clock  : " << time << '\n';
  std::cout << "Local time    : " << localTime << '\n';
  std::cout << "Berlin time   : " << berlinTime << '\n';
  std::cout << "New York time : " << newYorkTime << '\n';
  std::cout << "Tokyo time    : " << tokyoTime << '\n';
}
