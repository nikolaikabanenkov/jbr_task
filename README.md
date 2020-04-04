#### A simple spinlock implementation.

##### GenMC

An example of code that GenMC crashes on is given in `crash_genmc.cc`.

```
gdb genmc
(gdb) r crash_genmc.cc

Program received signal SIGSEGV, Segmentation fault.
llvm::DataLayout::getTypeSizeInBits (this=0x2f16738, Ty=0x0)
    at /usr/local/include/llvm/IR/DataLayout.h:569
569	  assert(Ty->isSized() && "Cannot getTypeInfo() on a type that is unsized!");
```

##### Requirements

* CMake at least 3.13;
* C++ compiler that supports at least C++11;
* (required for tests) libpthread.

##### Coding style

The project uses [Google coding style](https://google.github.io/styleguide/cppguide.html).
Use `clang-format --style=google -i` to format code.

##### Building

```
mkdir build && cd build
cmake ../
cmake --build ./
```

Run tests with `./spinlock_test`.
