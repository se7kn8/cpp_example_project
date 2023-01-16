#include "helper.hpp"
#include "robot.hpp"
#include "test.hpp"
#include <iostream>
#include <memory>
#include <optional>

namespace std {
void printHello() { cout << "Hello from std" << endl; }
} // namespace std

void printRobot(Robot &r) {
  std::cout << "Is my robot an enemy: " << r.isEnemy() << std::endl;
}

std::unique_ptr<Robot> createRobot(bool isAlly) {
  if (isAlly) {
    return std::make_unique<AllyRobot>(AllyRobot());
  } else {
    return std::make_unique<EnemyRobot>(EnemyRobot());
  }
}

std::optional<int> func(int p) {
    if(p != 0) {
        return 10 / p;
    } else {
        return std::nullopt;
    }
}

int main() {
  test::printHello();
  helper::printHello(5);
  std::printHello();
  /*
    Robot r("Kuka");
    r.kick();

     std::cout << "My robot name is " << r.getName() << std::endl;
  */
  AllyRobot a;
  EnemyRobot e;

  printRobot(a);
  printRobot(e);
  a.kick();

  int idA = a.getID();
  int idE = e.getID();

  test::showConst();

  std::unique_ptr<Robot> r1 = createRobot(true);
  std::unique_ptr<Robot> r2 = createRobot(false);

  std::unique_ptr<Robot> r1_new = std::move(r1);

  std::shared_ptr<Robot> r3 = std::make_shared<AllyRobot>(AllyRobot());
  std::shared_ptr<Robot> r3_copy = r3;
  std::weak_ptr<Robot> r3_weak = r3;

  std::cout << "R1: Is enemy: " << r1_new->isEnemy() << std::endl;
  std::cout << "R2: Is enemy: " << r2->isEnemy() << std::endl;
  std::cout << "R3: Is enemy: " << r3->isEnemy() << std::endl;
  std::cout << "R3C: Is enemy: " << r3_copy->isEnemy() << std::endl;

  if (r3_weak.expired()) {
  }

  std::optional<int> o = func(0);

  if(o.has_value()) {
    std::cout << "O has value " << o.value() << std::endl;
  } else {
    std::cout << "O doesn't have value " << std::endl;
  }

  return 0;
}
