#include <iostream>

using namespace std;

class Point2D
{
public:
    double x;
    double y;
};

class MyPoint3D
{
public:
    double x;
    double y;
    double z;
};

class Point3D : public Point2D
{
public:
    double z; // gcc warning when try to get alignof z.
};

int main()
{
    cout << "Size of char: " << sizeof(char) << endl;
    cout << "Size of int: " << sizeof(int) << endl;
    cout << "Size of float: " << sizeof(float) << endl;
    cout << "Size of double: " << sizeof(double) << endl;
    cout << "Size of Point2D: " << sizeof(Point2D) << endl;
    cout << "Size of Point3D: " << sizeof(Point3D) << endl;
    cout << endl;

    cout << "OffsetOf x in Point2D: " << offsetof(Point2D, x) << endl;
    cout << "OffsetOf y in Point2D: " << offsetof(Point2D, y) << endl;

    // Get offset of z field causes gcc warning as below
    // warning: offset of on non-standard-layout type 'Point3D' [-Winvalid-offsetof]
    // cout << "OffsetOf z in Point3D: " << offsetof(Point3D, z) << endl;

    cout << "OffsetOf z in MyPoint3D: " << offsetof(MyPoint3D, z) << endl;
    cout << endl;

    cout << "Alignof char: " << alignof(char) << endl;
    cout << "Alignof int: " << alignof(int) << endl;
    cout << "Alignof long: " << alignof(long) << endl;
    cout << "Alignof float: " << alignof(float) << endl;
    cout << "Alignof double: " << alignof(double) << endl;
    cout << "Alignof Point2D: " << alignof(Point2D) << endl;
    cout << "Alignof Point3D: " << alignof(Point3D) << endl;
    cout << endl;
}

// See this for POD and non-POD
//     https://docs.microsoft.com/en-us/cpp/cpp/trivial-standard-layout-and-pod-types?view=msvc-170

// Question: is this a POD?
class CoolClass
{
private:
    int field1;

public:
    int field2;
};

void inspect_pod()
{
    // GCC warning because CoolClass is not a POD.
    //   warning: offset of on non-standard-layout type 'CoolClass' [-Winvalid-offsetof]
    // cout << "OffsetOf field2: " << offsetof(CoolClass, field2) << endl;
}
