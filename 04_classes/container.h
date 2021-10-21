#pragma once

#include <iostream>

// A class with a pure virtual function is called an abstract class.
class Container {
public:
  
    virtual double &operator[](int) = 0; // pure virtual function
    virtual int     size() const = 0;    // const member function (§4.2.1)
    // destructor... this function has an (empty) implementation, but it can
    // be redefined by subclasses
    virtual ~Container() {} 
     
    void xpto() { std::cout << "xpto of Container class\n"; }
};

//void use(Container &c) 
//{ 
//    const int sz = c.size(); 
//    for (int i = 0; i != sz; ++i) {
//        std::cout << " Container i:" << i << "value:" << c[i] << "\r\n";
//    }
//}