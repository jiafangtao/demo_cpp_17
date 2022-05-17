#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

void printChar(char c) {
    cout << c <<endl;
}

int main() {
    string s = "hello, world";

    for_each(s.begin(), s.end(), printChar);

    // for_each returns the function (or functor) iteself.
    void * pRes = (void *)for_each(s.begin(), s.end(), printChar);
    assert(pRes == printChar);

    return 0;
}
