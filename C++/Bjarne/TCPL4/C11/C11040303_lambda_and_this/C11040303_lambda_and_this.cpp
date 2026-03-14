// C11040303_lambda_and_this.cpp 
#include <iostream>
#include <functional>
#include <thread>
#include <string>
#include <map>
#include <future>

using namespace std;

class Request {
  function<map<string, string>(const map<string, string>&)> oper {}; // operation
  map<string, string> values;                                        // arguments
  map<string, string> results;                                       // targets
public:
  Request(const string& s) {};        // parse and store request
  future<void> execute() {            // execute asynchronously
    return async([this]() { results = oper(values); });
  }
};

int main() {
  Request r("send email.");
  auto execution1 = r.execute();
}
