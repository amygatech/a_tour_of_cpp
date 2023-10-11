#include <iostream>

using namespace std;

template <typename T> 
T Max(T x, T y) {
    cout << typeid(T).name() << endl;

    return x > y ? x : y;
}
template <typename T> 
T Min(T a, T b) {
    cout << typeid(T).name() << endl; // T will be deduce as `int`
    return a < b ? a : b;
}

template char Max(char c, char y); // also creates an instatiation of template

int main() {

    // argument deduction

    auto ret = Max(3, 5);
    cout << "\n Max value :"<< ret << std::endl;

    Max(9.0f, 25.0f);
    //printf("\n MAX value : %f \n", ret);
    

    Max<double>(9, 25.0f); // EXPLICIT SPECIFY type of override compiler type
                           // argument deduction !!

    int (*pfn)(int, int) = Max; // intatiate Max template for integer types

    Min<float>(5.5f, 6.6f); // Implicit conversion happens here

    return 0;
}