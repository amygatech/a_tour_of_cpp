#pragma once

#include <iostream>
#include <stdexcept> // std::length_error
#include <algorithm> // std::copy

template <typename T> 
class Vector {
private:
    int size_ = 0;
    T * elem_ = nullptr;

public:
    Vector() 
    { 
        std::cout << "Default contruct \n";
    }
    // constructor: establish invariant, acquire resources
    explicit Vector(int size);

    // destructor: release resources
    ~Vector() { delete[] elem_; }

    // ... copy and move operators ...

    T &operator[](int i) const;
};

// Example to 
// show how to compile template functions in a
// separate file
template <typename T> void foo(T &val);