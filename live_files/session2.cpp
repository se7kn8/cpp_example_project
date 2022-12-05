#include <iostream>
#include <array>
#include <vector>
#include <cmath>

// Task for next week: 
// Create a vec2 class which has the following functions
class Vec2 {
    Vec2(int, int);
    void add(Vec2);
    void sub(Vec2);
    void len(Vec2);
};

void modify(int& i) {
    i++;
}

int square(int a) {
    return a * a;
}

void print(const std::string& s) {
    std::cout << s << std::endl;
}


class Point {
private:
    int x = 0;
    int y = 0;

public:

    Point() = default;

    Point(int v): x(v), y(v) {}

    Point(int x, int y): x(x), y(y) {
        std::cout << "Created point" << std::endl;
    }

    void setX(int new_x) {
        x = new_x;
    }

    void setY(int new_y) {
        y = new_y;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    double getLength() {
        return std::sqrt(x*x + y*y);
    }
};

int main() {

    int i = 5;

    std::cout << i << std::endl;
    int s = square(i);
    std::cout << s << std::endl;
    std::string s1 = "hello";
    s1[0] = 'b';
    print(s1);
    print(s1);
    print(s1);
    print(s1);

    std::array<int, 4> array = {1,2,3,4};

    /*
    for(size_t i = 0 ; i < array.size(); i++) {
        std::cout << array[i] << std::endl;
    }*/

    for(const int& i : array) {
        std::cout << i << std::endl;
    }

    std::vector<int> vector;
    vector.push_back(10);    
    vector.push_back(20);    
    vector.push_back(30);    

    std::cout << "Size of vector " << vector.size() << std::endl;
    for(const int& i : vector) {
        std::cout << i << std::endl;
    }



    Point p(1, 1);
    std::cout << p.getLength() << std::endl;

    
    Point p2;
    std::cout << p2.getLength() << std::endl;
    
    Point p3(2);
    std::cout << p3.getLength() << std::endl;


    return 0;
}