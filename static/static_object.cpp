#include <iostream>

using namespace std;

class Apple {
    int i;
    public:
        Apple() {
            i = 0;
            cout << "Inside constructor" << endl;
        }
        ~Apple() {
            cout << "Inside deconstructor" << endl;
        }
};

int main() {
    int x = 0;
    if (x == 0) {
        static Apple apple; // 将对象声明为 static
        // 对象将在 if 的 body 内构造，但是不会在此析构
    }
    cout << "end of main func" << endl;
    // apple 会在 main 函数结束后析构
}

// output
// Inside constructor
// end of main func
// Inside deconstructor