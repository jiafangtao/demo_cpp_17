#include <string>

using namespace std;

int main() {
    pair<int, int> pii(1, 2);
    pair<int, string> pis;


    //auto p = make_pair(100, "100");
    make_pair(100, "100");

}

// Question: what if a normal class and a template has the same name?
// Answer: compilation error. It looks like definition of template class
// has higher priority. Thus compiler raises error that the plain class has
// problem of not providing the types.
#ifndef _USE_TEMPLATES
class MyClass {
    public:
        void foo();
    
    private:
        string _somefield;
};
#endif

#ifdef _USE_TEMPLATES
template<typename T> class MyClass {
    public:
        void foo();

    private:
        int _someintfield;
};
#endif // _USE_TEMPLATES
