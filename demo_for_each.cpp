#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

void printChar(char c) {
    cout << c <<endl;
}

int main() {
    string s = "hello, world";

    // for_each returns the function (or functor) iteself.

    // ignore the return value as always.
    for_each(s.begin(), s.end(), printChar);

    // C-style brute force. Not a manner of civilization ...
    void * pRes = (void *)for_each(s.begin(), s.end(), printChar);
    assert(pRes == printChar);

    // capture the return value with 'auto'
    auto result = for_each(s.begin(), s.end(), printChar);
    result('O');
    // result("oops"); // This won't compile.

    return 0;
}

//TODO: try for_each with complex types and loop with functors.
