#include <iostream>
using namespace std;

namespace first {
int x = 5;
int y = 10;
} // namespace first

namespace second {
double x = 3.1416;
double y = 2.7183;
} // namespace second

namespace variables {
int a = 100;
int b = 200;
} // namespace variables
int add(int &x, int &y) { return (x + y); }

int main() {
    int a = 75;
    int b = 75;
    cout << "The sum of the variables in global scope = " << add(a, b) << "\n";
    cout << "The sum of the variables in variables namescope = "
         << add(variables::a, variables::b) << "\n";

    using first::x;
    using second::y;
    cout << "\r\n using namespace \r\n";
    cout << x << '\n';
    cout << y << '\n';
    cout << first::y << '\n';
    cout << second::x << '\n';
    return 0;
}