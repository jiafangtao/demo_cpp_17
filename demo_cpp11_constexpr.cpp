#include <iostream>

using namespace std;

const int getMaxCount() { return 3; }

constexpr int getMaxCountWithConstexpr() { return 3; }

enum SomeEnum
{
    COUNT_MAX = getMaxCountWithConstexpr()
};

int main()
{
    // this won't compile. The size of array must be known at compliation time
    // int array[getMaxCount()] = {0};

    int array2[getMaxCountWithConstexpr()] = {1, 2, 3};
    for (int i : array2)
    {
        cout << i << endl;
    }

    cout << endl;
    cout << SomeEnum::COUNT_MAX << endl;
}
