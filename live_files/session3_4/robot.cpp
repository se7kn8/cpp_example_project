#include "robot.hpp"
#include <iostream>
/*
Robot::Robot(std::string robot_name)
: name(robot_name) {
    std::cout << "Created robot with name: " << name << std::endl;
    // code for constructor
}

std::string Robot::getName() {
    return name;
}

void Robot::kick() {
    std::cout << "Kicking...!!" << std::endl;
}*/

void Robot::updatePosition(int x1, int y1, int rot1) {
    this->x = x1;
    this->y = y1;
    this->rot = rot1;
    if (x % 20 == 0) {
        this->state = RobotState::ON_WITH_KICKER;
    }
}

int Robot::getX() {
    return this->x;
}

int Robot::getY() {
    return this->y;
}

int Robot::getRot() {
    return this->rot;
}

void AllyRobot::kick() {
    this->state = RobotState::BURNING;
    std::cout << "Kicking at x=" << this->x << " y=" << this->y << std::endl;
    this->state = RobotState::OFF;
}

bool AllyRobot::isEnemy() {
    return false;
}

int AllyRobot::getID() {
    return 1;
}

bool EnemyRobot::isEnemy() {
    return true;
}

bool SuperAllyRobot::isEnemy() {
    return true;
}