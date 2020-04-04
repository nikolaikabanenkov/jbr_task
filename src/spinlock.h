#ifndef JBR_TASK_SPINLOCK_H_
#define JBR_TASK_SPINLOCK_H_

#include <atomic>

namespace jbr_task {
//
// A simple spinlock implementation.
//
class spinlock {
 public:
  spinlock();
  spinlock(const spinlock&) = delete;
  ~spinlock() = default;

  // Locks the spinlock.
  // Will block the thread if the spinlock is already locked.
  void lock();

  // Tries to lock the spinlock.
  // Returns false if the spinlock is already locked, returns true otherwise.
  bool try_lock();

  // Unlocks the spinlock.
  // Must be called from a thread that have locked the spinlock.
  void unlock();

 private:
  std::atomic_bool locked_;
};
}  // namespace jbr_task

#endif  // JBR_TASK_SPINLOCK_H_
