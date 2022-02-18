
/*
* Problem 4. Swap two numbers without using any third variable
* This is again one of the simplest and most commonly used bit hacks. 
* The idea is to use XOR operators to swap two numbers by their property x ^ x = 0. 
* The following C++ program demonstrates it:
*/

#include <iostream>
using namespace std;

void swap(int &x, int &y) 
{
    if (x != y) {
        x = x ^ y;
        y = x ^ y;
        x = x ^ y;
    }
}

int main() {
    int x = 3, y = 4;

    cout << "Before swap: x = " << x << " and y = " << y;
    swap(x, y);
    cout << "\nAfter swap: x = " << x << " and y = " << y;

    return 0;
}
