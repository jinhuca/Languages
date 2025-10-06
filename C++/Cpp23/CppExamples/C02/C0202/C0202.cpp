import std;

std::vector<int> get_next_row(const std::vector<int>& last_row) {
  std::vector next_row { 1 };
  if(last_row.empty()) {
    return next_row;
  }
  for(size_t idx = 0; idx + 1 < last_row.size(); ++idx) {
    next_row.emplace_back(last_row[idx] + last_row[idx + 1]);
  }
  next_row.emplace_back(1);
  return next_row;
}

std::vector<std::vector<int>> generate_triangle(int rows) {
  std::vector<int> data;
  std::vector<std::vector<int>> triangle;

  for(int row = 0; row < rows; ++row) {
    data = get_next_row(data);
    triangle.push_back(data);
  }
  return triangle;
}

void display_triangle(const std::vector<std::vector<int>>& data) {
  for(auto& vec : data) {
    for(auto& item : vec) {
      std::cout << item << ' ';
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}

int main() {
  auto triangle = generate_triangle(5);
  display_triangle(triangle);
}
