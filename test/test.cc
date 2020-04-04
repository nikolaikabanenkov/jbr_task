#include <spinlock.h>
#include <cassert>
#include <chrono>
#include <thread>

// lock() and unlock()
bool test1() {
  jbr_task::spinlock sl;
  sl.lock();

  bool flag = false;
  std::thread th(
      [](jbr_task::spinlock& sl, bool& flag) {
        sl.lock();
        flag = true;
      },
      std::ref(sl), std::ref(flag));

  std::this_thread::sleep_for(std::chrono::milliseconds(50));

  bool first_check = flag;
  sl.unlock();
  th.join();
  bool second_check = flag;

  return !first_check && second_check;
}

// try_lock()
bool test2() {
  jbr_task::spinlock sl;

  std::thread th(
      [](jbr_task::spinlock& sl) {
        sl.lock();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        sl.unlock();
      },
      std::ref(sl));

  std::this_thread::sleep_for(std::chrono::milliseconds(50));

  bool first_check = sl.try_lock();
  th.join();
  bool second_check = sl.try_lock();

  return !first_check && second_check;
}

int main() {
  assert(test1() && "Test 1 failed.");
  assert(test2() && "Test 2 failed.");

  return 0;
}
