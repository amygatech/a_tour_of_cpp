#include "03_vector.h"
#include <list>


using std::cout;
using std::endl;

void foo_int(const Vector<int> &v) {
    // v.at(0) = 10; // error: cannot assign to return value because function
    // 'at' returns a const value v[1] = 10; // error: cannot assign to return
    // value because function 'operator[]' returns a const value

    int x0 = v.at(0); // calls directly "const T& at(int i) const"
    int x1 = v[1];    // calls directly "const T& operator[](int i) const"

    cout << "\nx0 = " << x0 << endl;
    cout << "x1 = " << x1 << endl;
    cout << "--------------\n\n";
}

template <typename T> 
void rangeForConstObjects(const Vector<T> &v) {
    cout << "rangeForConstObjects()" << endl;
    cout << "size = " << v.size() << endl;

    // This range-for calls: "const T* begin() const" and "const T* end() const"
    // from Vector
    for (const auto &x : v) {
        cout << x << endl;
    }
    cout << "\n";
}

//=================
int main() {
    cout << "### vi initialization\n";
    Vector<int> vi{1, 2, 3};
    vi.print();
    cout << endl;

    cout << "##### NON-CONST OBJECTS #####\n";
    // getters by non-const objects
    cout << "GETTERS\n";
    cout << "int x0 = vi.at(0);\n";
    int x0 = vi.at(0); // calls "T& at(int i)" and then internally calls "const
                       // T& at(int i) const"

    cout << "\nint x1 = vi[1];\n";
    int x1 = vi[1]; // calls "T& operator[](int i)" and then internally calls
                    // "const T& operator[](int i) const"

    cout << "\nx0 = " << x0 << endl;
    cout << "x1 = " << x1 << endl;
    cout << "--------------\n\n";

    // setters by non-const objects
    cout << "SETTERS\n";
    cout << "vi.at(0) = 10;\n";
    vi.at(0) = 10; // calls "T& at(int i)" and then internally calls "const T&
                   // at(int i) const"

    cout << "\nvi[1] = 20;\n";
    vi[1] = 20;
    cout << endl;
    vi.print();
    cout << "--------------\n\n";

    cout << "##### CONST OBJECTS #####\n";
    foo_int(vi);

    cout << "### double\n";
    Vector<double> vd = {1.5, 2.5, 3.5};
    vd.print();
    cout << "--------------\n\n";


    cout << "### string\n";
    Vector<std::string> vs = {"zero", "one", "two"};
    vs.print();
    cout << "--------------\n\n";


    //-----------------------------------
    rangeForConstObjects(vi);
    cout << endl;
    vi.print();
    cout << "--------------\n\n";

    cout << "rangeFor Non-Const Objects but Const Elements in For\n";
    for (const auto &x : vi) {
        cout << x << endl;
    }
    cout << "\n";
    cout << "--------------\n\n";

    cout << "rangeFor Non-Const Objects and Elements in For\n";
    for (auto &x : vi) {
        x = 17;
    }
    vi.print();
    cout << "\n";
    cout << "--------------\n\n";


    return 0;
}