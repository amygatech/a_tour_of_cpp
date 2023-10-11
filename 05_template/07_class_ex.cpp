#include <iostream>
#include <utility>
#include <functional>

using namespace std;

template <typename T1, typename T2> class pair_ex {
public:
    T1 first;
    T2 second;
};
pair_ex<int, char> pair1;
pair_ex<float, float> pair2;


template <typename T1, typename T2> 
pair<T1, T2> make_pair(T1 &&t1, T2 &&t2) {
    return {forward<T1>(t1), forward<T2>(t2)};
}
    

template <typename T>
T min_val(T a, T b) 
{ 
    return a < b ? a : b;
}

//variable template
template <class T>
constexpr T pi = T(3.1415926535897932385L); // variable template

template <uint32_t val> constexpr auto fib = fib<val - 1> + fib<val - 2>;
template <> constexpr auto fib<0> = 0;
template <> constexpr auto fib<1> = 1;





int main() {
    //class template example
    pair1.first = 2;
    pair1.second = 'T';
    pair_ex<int, char> p1{1, 'A'};


    //function
    auto ret = min_val<int>(3, 5);
    printf(" \n min val: %d ", ret);
    auto ret1 = min_val<float>(4.1f, 0.1f);
    printf(" \n min val: %.2f \n", ret1);
 
    //example variable
    cout << pi<float> << endl; // 3.14159
    cout << pi<int> << endl;   // 3
    cout << fib<10> << endl;   // 55


    return 0;
}