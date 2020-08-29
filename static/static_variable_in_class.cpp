#include<iostream> 
using namespace std; 

class Apple { 
public: 
    static int i; 

    Apple() { 
        // Do nothing 
    }; 
}; 

/* error: 静态变量不能使用构造函数进行初始化

// 下边的程序尝试为多个对象创建静态变量 i 的多个副本。但这是错误的
int main() { 
    Apple obj1; 
    Apple obj2; 
    obj1.i =2; 
    obj2.i = 3; 
        
    // prints value of i 
    cout << obj1.i<<" "<<obj2.i; 
} 
*/

// 类中的静态变量应由用户在类外初始化
int Apple::i = 1;

int main() {
    Apple obj;
    cout << obj.i;
}