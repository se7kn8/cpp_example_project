#include <iostream>
#include <string>

// Structs can be defined the same as in c
struct Point {
    int x;
    int y;
};

int main() {
    // Basic data types
    bool b = false;
    short s = 2;
    int i = 1;
    long l = 1;
    double d = 0.1;
    float f = 0.1f;
    std::string string = "test";

    // Print to console
    std::cout << "My int is " << i << " and my string is " << string << std::endl;

    // For loop
    for (int i = 0; i < 10; i++) {

    }

    // if block
    if(b) {

    } else {
        
    }

    // Read a number from the console
    int number = 0;
    std::cin >> number;
    std::cout << "My number is " << number << std::endl;

    // Struct init
    Point p;
    p.x = 5;
    p.y = 4;

    // Print point
    Point p2{1,2};
    std::cout << "Point 2 x=" << p2.x << " y= " << p2.y << std::endl;


    return 0;
}