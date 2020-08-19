#include <iostream>
using namespace std;

void func(const int i) {
    i = 10; //! error: can't assign to read-only parameter
    cout << i << endl;
}
int main() {
    func(1);
    return 0;
}