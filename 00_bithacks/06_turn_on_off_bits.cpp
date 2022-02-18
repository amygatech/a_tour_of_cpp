
/*
* Turn off/on k’th bit in a number
*/

/* 
To set a bit
number |= 1UL << n;
To clear a bit
number &= ~(1UL << n);
*/

#include <iostream>
#include <bitset>
using namespace std;


/*----------------------------------------
For example, consider n = 20 and k = 3.

00010100    &                 (n = 20)
11111011                    ~ (1 << (3-1))
~~~~~~~~
00010000
*/

// Clear bit
// number &= ~(1UL << n);
// Function to turn off k'th bit in `n`
int turnOffKthBit(int number, int k) 
{ 
    //cout << number << " in binary is " << bitset<8>(number) << endl;
    number &= ~(1UL << (k - 1)); 

    return number;
}


//setting bit
// number |= 1UL << n;
// That will set the nth bit of number. 
// n should be zero, if you want to set the 1st bit and so on upto n-1, if you want to set the nth bit.
// Use 1ULL if number is wider than unsigned long; 
// 
// Function to turn on k'th bit in `n`
int turnOnKthBit(int number, int k) 
{ 
    return number |= (1UL << (k - 1)); 
}


/*
The idea is to use bitwise << and & operators. 
Using the expression 1 << (k - 1), we get a number with all bits 0, except the k'th bit. 
If we do bitwise AND of this expression with n, 
i.e., n & (1 << (k - 1)), any non-zero value indicates that its k'th bit is set.

For example, consider n = 20 and k = 3.

00010100    &               (n = 20)
00000100                    (1 << (3-1))
~~~~~~~~
00000100                    non-zero value
*/

//checking a bit
// bit = (number >> n) & 1U;
//That will put the value of the nth bit of number into the variable bit.
bool isKthBitSet(int number, int k) 
{ 
    return (number & (1 << (k - 1))) != 0; 

    //int bit;
    //bit = (number >> k - 1) & 1U;
    //return (bit != 0);    
}

int main() {
    int n = 20;
    int k = 3;

    int num = 20;
    int j = 4; 

    cout << n << " in binary is " << bitset<8>(n) << endl;
    printf("\n Turning %d'th bit off\n", k);

    n = turnOffKthBit(n, k);
    cout << n << " in binary is " << bitset<8>(n) << endl;


    cout << "\n===========================\n";
    cout << num << " in binary is " << bitset<8>(num) << endl;
    printf( "Turning %d'th bit on\n", j);

    num = turnOnKthBit(num, j);
    cout << num << " in binary is " << bitset<8>(num) << endl;


    n = 20;
    k = 3;
    cout << "\n===========================\n";
    cout << n << " in binary is " << bitset<8>(n) << endl;
    cout << "check k : " << k << "bit \n";

    if (isKthBitSet(n, k)) {        
        cout << "k'th bit is set";
    } else {
        cout << "k'th bit is not set";
    }

    return 0;
}