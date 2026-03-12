#pragma once
#include <map>
#include <string>

std::map<std::string, double> table;

void initialize_symbol_table() {
  table["pi"] = 3.1415926535897932385;
  table["e"] = 2.7182818284590452354;
}