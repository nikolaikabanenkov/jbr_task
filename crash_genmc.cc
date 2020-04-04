// GenMC crashes when an instance of a class that contains BOTH member variable and member function is created. 
class T {
  int bar;

 public:
  void foo() {}
};

int main() {
  T t;
  t.foo();
  return 0;
}

