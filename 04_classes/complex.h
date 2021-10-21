#pragma once

#include <iostream>

class complex {
private:
    double real_, image_; //represenation two doubles

public:
    complex() : real_{0}, image_{0} { //construct
        std::cout << "Default Constructor: complex()" << std::endl;
    }
    complex(double real) : real_{real}, image_{0} {} //construct complex from one scalar
    complex(double real, double image) : real_{real}, image_{image} {  //construct complex from two scalar
        std::cout << "Constructor: complex(double real, double image)"
                  << std::endl;
    }

    // setter
    void real(double in_real) {
        real_ = in_real;
        // this->real_ = in_real; // let's avoid using 'this' to have a less
        // verbose code
    }

    // getter: const does not allow to change members from the class
    double real() const { return real_; }

    // we could use the prefix m_ for the method parameters to better identify
    // it as a parameter
    void image(double in_image) { image_ = in_image; }

    double image() const { return image_; }

    // operator overloading
    complex &operator+=(const complex &z) {
        // a private member from an object passed as an argument can be accessed
        // directly inside the function if the object is of the current class
        real_ += z.real_;

        // to strictly respect OO, let us use getters instead
        image_ += z.image();

        // 'this' is a pointer to the class/current object
        // so, *this corresponds to the own object
        // as the function returns a reference, a copy of the current object is
        // not returned
        return *this;
    }

    complex &operator-=(const complex &z) {
        real_ -= z.real();
        image_ -= z.image();

        return *this;
    }

    // current_object + another_object
    // this function is called by the current_object
    // 'const' guarantees that the (this) members are not changed
    complex operator+(const complex &z) const {
        return complex{real_ + z.real(), image_ + z.image()};
    }


    complex operator-(const complex &z) {
        return complex{real_ - z.real(), image_ - z.image()}; // another way
    }

    bool operator==(const complex &z) {
        return (real_ == z.real_) && (image_ == z.image_);
    }

    bool operator!=(const complex &z) {
        return !(*this == z); // it calls the overloaded operator ==
    }

    // implementation is in complex.cpp
    void print();

   
  
};


void complex::print() {
    std::cout << "Real: " << real_ << std::endl;
    std::cout << "Image: " << image_ << std::endl;
}
