// Problem 1. Check if an integer is even or odd

/*-----------------------------------------------------
* The expression n & 1 
returns value 1 or 0 depending upon whether n is odd or even.

00010100    &                   (n = 20)
00000001                        (1)
~~~~~~~~
00000000
 
 
00010101    &                   (n = 21)
00000001                        (1)
~~~~~~~~
00000001
*/

#include <iostream>
using namespace std;

int main() 
{
    int num = 20;

    if (num & 1) {
        std::cout << " \n The number : " << num << " is odd \n";
    } 
    else {
        std::cout << " \n The number : " << num << " is event \n";
    }

    return 0;
}