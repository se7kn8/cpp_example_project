#include <functional>
#include <iostream>
#include <memory>
#include <numeric>

class Button {

public:
  virtual void klick() {}
};

class CustomButton : public Button {
public:
  void klick() override { std::cout << "Hello World" << std::endl; }
};

class FunctionalButton {
public:
  std::function<void(bool)> klick_handler;
  void klick(bool shift) { klick_handler(shift); }
};

void on_klick(bool shift) { std::cout << "Functional button" << std::endl; }

int main() {
    
  std::unique_ptr<Button> button = std::make_unique<CustomButton>();

  button->klick();

  FunctionalButton fbutton;
  fbutton.klick_handler = on_klick;
  fbutton.klick(false);

  FunctionalButton lambda;
  {

    int i = 5;
    int j = 6;
    lambda.klick_handler = [i, j](bool shift) {
      std::cout << "Hello from lambda.  Shift: " << shift << " I= " << i
                << " J= " << j << std::endl;
    };
  }

  lambda.klick(false);
  lambda.klick(true);

  std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int i = 0;
  for (const auto &element : v) {
    i += element;
  }

    const auto acc_square = [](int acc, int element){
        return acc + element * element;
  };

  int i2 = std::accumulate(v.begin(), v.end(),  0, acc_square);

  
  std::vector<int> v2{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

  
  int i3 = std::accumulate(v2.begin(), v2.end(),  0, acc_square);

  std::cout << "I: " << i << std::endl;
  std::cout << "I2: "<< i2 << std::endl;
  std::cout << "I3: "<< i3 << std::endl;
}
