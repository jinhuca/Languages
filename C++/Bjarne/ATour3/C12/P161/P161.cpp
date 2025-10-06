// P161.cpp : range checking
import std;

void silly(std::vector<int>& nums) {
  int i = nums[nums.size()];
  std::cout << i << '\n';
}

void silly2(std::vector<int>& nums) {
  int i = nums.at(nums.size());
  std::cout << i << '\n';
}

int main() {
  std::vector<int> n1 = { 0,1,2,3 };
  silly(n1);
  //silly2(n1);
}
