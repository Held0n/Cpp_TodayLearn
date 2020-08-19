#include <iostream>
using namespace std;

int main() {
    const int* ptr;  // variable read-only
    int val = 3;
    ptr = &val;  // ok! Assign to pointer `ptr`
    int* ptr1 = &val;
    *ptr = 4;  //! error: *ptr is a read-only variable
}