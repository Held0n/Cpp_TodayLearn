#include <iostream>
using namespace std;

int main() {
    const int *ptr;
    *ptr = 10; //! error: const varible can not be assigned
}