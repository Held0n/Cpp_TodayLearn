#include <iostream>
using namespace std;

int main() {
    const int num = 0;
    int* const ptr = &num;  //! error: Assign an un-const variable to const pointer
    cout << *ptr << endl;
}