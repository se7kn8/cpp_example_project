#include <iostream>
#include <string>

namespace test {

void printHello() { std::cout << "Hello test" << std::endl; }

void printName(const std::string &name) { std::cout << name << std::endl; }

class IntHolder {
  int i;
  // Very large field

public:
  IntHolder(int i) : i(i) {
    std::cout << "Creating class intholder" << std::endl;
  }
  ~IntHolder() {
    std::cout << "Deleting class intholder" << std::endl;
  }
  IntHolder(IntHolder&) = delete;

  int getInt() const { return i; }
  void setInt(int i) { this->i = i; }
};

void printHolder(const IntHolder& h) {
    std::cout << h.getInt() << std::endl;
} 

void showConst() {
  int i = 5;
  const int j = 6;
  std::string hello = "Hello";
  printName(hello);
  i = 6;

  IntHolder holder(12);

{
    IntHolder h2(24);
}

  printHolder(holder);
  printHolder(holder);
}
} // namespace test