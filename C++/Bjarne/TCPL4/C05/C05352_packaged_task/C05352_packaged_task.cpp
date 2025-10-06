// C05352_packaged_task.cpp
import std;

double accum(double* beg, double* end, double init) {
  // compute the sum of [beg:end) starting with the initial value int
  return std::accumulate(beg, end, init);
}

void comp2(std::vector<double>& v) {
  using Task_type = double(double*, double*, double);     // type of task

  std::packaged_task<Task_type> pt0 { accum };        // package the task (i.e., accum)
  std::packaged_task<Task_type> pt1 { accum };

  std::future<double> f0 { pt0.get_future() };          // get hold of pt0's future
  std::future<double> f1 { pt1.get_future() };          // get hold of pt1's future

  double* first = &v[0];
  std::thread t1 { std::move(pt0), first, first + v.size() / 2, 0 };        // start a thread for pt0
  std::thread t2 { std::move(pt1), first + v.size() / 2, first + v.size(), 0 };    // start a thread for pt1
  // ...
  auto res = f0.get() + f1.get();                 // get the results
  // ...
}

int main() {

}
