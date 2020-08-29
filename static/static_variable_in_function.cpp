#include <iostream>
#include <string>

using std::cout;

void demo() {
    static int cnt = 0; // static variable
    cout << cnt << " ";

    // value is updated and will be carried to next function calls
    cnt++;
}

int main() {
    for (int i = 0; i < 5; i++) {
        demo();
    }
    return 0;
}

// 变量 cnt 被声明为 static，因此，它的值通过函数调用来传递
// 每次调用函数时，都不乎对变量 cnt 进行初始化，也就是说 cnt 只初始化一次(只分配一次空间)