#include <iostream>
using namespace std;

int main() {
    int num = 0;
    int* const ptr = &num;  // const pointer must initialize
    num = 5;
    cout << num << endl;
    int* t = &num;
    *t = 1;
    cout << *ptr << endl;

    const int* var;
    *var = num; //! error: can not assign to const variable
}