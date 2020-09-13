#include <iostream>

using namespace std;

void f(int i) {
    cout << "void f(int i)" << endl;
}

void f(void *p) {
    cout << "void f(void *p)" << endl;
}

int main() {
    if (NULL == 0) {
        cout << "NULL == 0" << endl;
    }

    f(nullptr);

    nullptr_t nullptr_type;
    f(nullptr_type);

    return 0;
}