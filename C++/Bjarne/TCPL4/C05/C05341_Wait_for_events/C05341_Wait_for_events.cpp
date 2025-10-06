// C05341_Wait_for_events.cpp 
import std;
using namespace std::chrono;

void f() {
  auto t0 = high_resolution_clock::now();
  std::this_thread::sleep_for(milliseconds { 20 });
  auto t1 = high_resolution_clock::now();
  std::cout << duration_cast<nanoseconds>(t1 - t0).count() << " nanoseconds passed.\n";
}

class Message {   // object to be communicated
  // ...
};

std::queue<Message> mqueue;       // the queue of messages
std::condition_variable mcond;    // the variable communicating events
std::mutex mmutex;                // the locking mechanism

void consumer() {
  while (true) {
    // acquire mmutex
    std::unique_lock<std::mutex> lck { mmutex };

    // release lck and wait until not empty
    // re-acquire lck upon wakeup
    mcond.wait(lck, [this] { return !mqueue.empty(); });

    auto m = mqueue.front();    // get the message
    mqueue.pop();
    lck.unlock();                       // release lck
    // ... process m ...
  }
}

void producer() {
  while (true) {
    Message m;
    // ... fill the message ...
    std::unique_lock<std::mutex> lck { mmutex };  // protect operations
    mqueue.push(m);
    mcond.notify_one();     // notify, and release lck (at end of scope)
  }
}

int main() {
  f();
}
