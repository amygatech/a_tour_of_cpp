/*
* Write a C program to count bits set in an integer
*/

#include <iostream>

int main() {
    unsigned int num = 8;
    int          count = 0;

    printf("\n Number of bits set in %d ", num);
    for (; num != 0; num >>= 1) { 
        if (num & 1) { 
            count++;
        }
    }

    printf(" \t count = [%d]\n", count);


    printf("\n===============Method 2 ==========\n");
    num = 5;
    count = 0;
    printf("\n Number of bits set in %d ", num);

    while (num) {
        count++;
        num = num & (num - 1);
    }
    printf(" \t Method 2 --> count = [%d]\n", count);

    return 0;
}
