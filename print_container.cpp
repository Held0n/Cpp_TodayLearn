#include <iostream>
#include <vector>
#include <iterator>

using std::copy;
using std::vector;

int main() {
    vector<int> vec{1, 2, 3, 4, 5};
    copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));

}