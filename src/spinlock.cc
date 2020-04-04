#include "spinlock.h"

namespace jbr_task {
spinlock::spinlock() : locked_{false} {}

void spinlock::lock() {
  while (locked_) {
  }
  locked_ = true;
}

bool spinlock::try_lock() {
  if (locked_) return false;
  return locked_ = true;
}

void spinlock::unlock() { locked_ = false; }
}  // namespace jbr_task
