#include <iostream>

using namespace std;

class Apple {
    public:
        static void print() {
            cout << "This is an apple.\n";
        }
};

int main() {
    Apple apple;
    apple.print(); // 可以使用 `.` 来访问类中的 static function
    Apple::print(); // 与类中的静态变量类似，建议使用 `类::` 来调用静态函数
    // static member function 可以访问 static member variable
    // 但是无法访问 非 static 的 variable 和 function
}

// output 
// This is an apple.
// This is an apple.