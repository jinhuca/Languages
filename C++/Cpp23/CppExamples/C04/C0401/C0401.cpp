import std;

// Listing 4.1 Creating a specific date
void create_date()
{
  auto new_year_eve = std::chrono::year_month_day(
    std::chrono::year(2024),
    std::chrono::month(12),
    std::chrono::day(31)
  );
  std::cout << new_year_eve << "\n";
}

// Listing 4.2 Duration between two time points
void duration_to_end_of_year()
{
  std::chrono::time_point now = std::chrono::system_clock::now();
  constexpr auto year = 2022;
  auto new_years_eve = std::chrono::year_month_day(
    std::chrono::year(year),
    std::chrono::month(12),
    std::chrono::day(31)
  );
  auto event = std::chrono::sys_days(new_years_eve);
  std::chrono::duration dur = event - now;
  std::cout << dur << " until event\n";
}

//Listing 4.4 Use duration to move to a coarser representation
void durations()
{
  using namespace std::chrono;
  auto nearly_a_day = hours{ 23 };
  days a_day = duration_cast<days>(nearly_a_day);
  hours round_trip = a_day;
  std::cout << nearly_a_day << " cast to " << a_day
    << " and cast back to " << round_trip << '\n';
}

int main()
{
  create_date();
  duration_to_end_of_year();
  durations();
}
