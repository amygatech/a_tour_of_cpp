//chapter 2 User Defined Data Type: Classes
#include <iostream>
using namespace std;

class Vector {
public:
    Vector(int s) : elem{new double[s]}, sz{s} {}; //construct a vector
    double &operator[](int i) { return elem[i]; } //element access: subscripting
    int     size() { return sz; }

private:
    double *elem; //pointer to the element
    int     sz; // the number of elements.
};

// method for sum
double read_and_sum(int s) {
    Vector v(s); //make vector of s elements

    for (int i = 0; i != v.size(); i++) {
        cout << "Enter Number\n";
        cin >> v[i]; // read into elements
    }
    double sum = 0;
    for (int i = 0; i != v.size(); i++) {
        sum += v[i]; //take the sum of the elments
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