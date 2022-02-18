//Problem 3: Add 1 to an integer

/*---------------------------------------------------------
* The expression -~x will add 1 to an integer x. 
* We know that to get negative of a number, invert its bits and add 1 to it 
  (Remember negative numbers are stored in 2’s complement form), i.e.,
          -x = ~x + 1;
          -~x = x + 1 (by replacing x by ~x)
          x = -~x -1
*/

#include <iostream>
#include <bitset>

using namespace std;

int main() {
    int x = 4;
    int y = 7;

    cout << " \t x= " << x << " in binary is " << bitset<8>(x) << endl;
    cout << "\t ~x = "  << ~x << " in binary is " << bitset<8>(~x) << endl;

    cout << "x = " << x << " \t the ~x = " << ~x << endl;

    cout << -x << "\t -x= ~x +1 " << (~x + 1) << endl;
    cout << x << " + " << 1 << " is " << -~x << endl;

    x = -5;
    cout << x << " + " << 1 << " is " << -~x << endl;

    x = 0;
    cout << x << " + " << 1 << " is " << -~x << endl;


    cout << " y = -~y - 1 "
         << " with y =" << y << ", and -~y - 1 = " << -~y - 1 << endl;

    return 0;
}