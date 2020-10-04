// User Defined Data Type: Structures

#include <iostream>
using namespace std;

struct Vector {
    int     size;
    double *elem;
};

// initializtion of the data type
void vector_init(Vector &v, int size) {
    v.elem = new double[size];
    v.size = size;
}

// method for sum
double read_and_sum(int size) {
    Vector v;
    vector_init(v, size);

    for (int i = 0; i != size; i++) {
        cout << "Enter Number\n";
        cin >> v.elem[i];
    }
    double sum = 0;
    for (int i = 0; i != size; i++) {
        sum += v.elem[i];
    }
    return sum;
}

// main method
int main() {
    int size = 5; // can be any integer
    int sum = 0;
    sum = read_and_sum(size);
    cout << "The sum of the numbers = " << sum << "\n";
    return 0;
}