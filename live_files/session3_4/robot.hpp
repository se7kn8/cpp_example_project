#pragma once

#include <string>
/*
class Robot {
public:
  Robot(std::string robot_name);

  std::string getName();

  void kick();
 private: 
 std::string name;
};*/

enum class RobotState {
    OFF,
    ON,
    ON_WITH_DRIBBLER,
    ON_WITH_KICKER,
    BURNING,
};

/**
 * @brief Represents a robot
 * A robot contains ....
    .....
 */
class Robot {
public:
    virtual ~Robot() = default;
    void updatePosition(int x, int y, int rot);
    int getX();
    int getY();
    int getRot();
    virtual bool isEnemy() = 0;
    virtual int getID() {
        return 0;
    }
protected:
    int x{0};
    int y{0};
    int rot{0};
    RobotState state{RobotState::OFF};
};

class AllyRobot : public Robot {
public:
    void kick();
    bool isEnemy() override;
    int getID() override final;
};

class EnemyRobot : public Robot {
public:
    bool isEnemy() override;
};

class SuperAllyRobot: public AllyRobot {
    bool isEnemy() override;
};