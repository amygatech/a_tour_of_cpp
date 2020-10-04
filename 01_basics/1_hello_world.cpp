
#include <iostream>
using namespace std; //make names for std visible with std::

double square(double x) 
{
    return x * x; 
}

void print_square(double x) {
    cout << "the square of: " << x << " is : " << square(x) << "\r\n";
}

/// <print_args>
/// Function take an integer, float, or string as argugemt
/// </print_args>
template <typename T> void print_line (const T &arg) {
    if constexpr (std::is_integral_v<T>) {
        std::cout << "Integer num :" << arg << "\r\n";
    } 
    else if constexpr (std::is_floating_point_v<T>) {
        std::cout << "Float: " << arg << "\r\n";
    } 
    else if constexpr (std::is_pointer_v<T>) {
        std::cout << "It's pointer: " << arg << "\t pointer value: " << *arg
                  << "\r\n";
    } 
    else {
        std::cout << " ARG: " << arg << "\r\n";
    }
}//end print_line function

///--------------------------------------
/// Function take a list of args
/// 
template <typename... Args> void printWithInfo(Args... arg) {
    (print_line(arg), ...);
}


int main() {
    float val = 2.56f;
    std::string test {"Hello TESTING"};

    std::cout << "Hello World!" << std::endl;
    print_square(1.234);

    // function take any print value
    print_line(12);
    print_line(15.02);
    print_line(&val);
    print_line(test);

    std::cout
        << "\r\n-------------Using template print all args-----------\r\n";
    printWithInfo(11, 25.01, test);

   
}
