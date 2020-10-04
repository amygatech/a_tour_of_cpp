#include "Vector.h"
#include <cmath>

using namespace std;

Vector::Vector(int s) : elem{new double[s]}, sz{s} {};
double &Vector::operator[](int i) { return elem[i]; }
int             Vector::size() { return sz; }

// user.cpp
double sqrt_sum(Vector &v) {
    double sum = 0;

    for (int i = 0; i != v.size(); ++i) {
        std::cout << "v [" << i << "]: " << v[i] << "\r\n"; 
        std::cout << "sqrt(v[i]) " << sqrt(v[i]) << "\r\n";
        sum += sqrt(v[i]);
    }
    return sum;
}

int main() {
    double sum = 0;
    int    size = 5;
    Vector v(size);
    for (int i = 0; i != v.size(); ++i) {
        cout << "Enter a number:\n";
        cin >> v[i];
    };
    sum = sqrt_sum(v);
    cout << "The sum of square roots= " << sum << "\n";
    return 0;
}