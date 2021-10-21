
#include <iostream>

void print() {
    int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "Refreshed Old for syntax\n";
    
    for (auto i = 0; i < 10; i++)
         std::cout << "[" << i << "] = " << v[i] << std::endl;
    std::cout << std::endl;
    
    std::cout << "New Cpp for-syntax\n";
    // for every element of v, from the first to the last, place a COPY in x,
    // that is, x is a different variable (memory position) of v[i]
    for (auto x : v)
        std::cout << x << "\n";
    std::cout << std::endl;
    
    std::cout << "New Cpp for-syntax - literal arrays\n";
    // it also works for literal arrays
    for (auto x : {0, 1, 2, 3, 4, 5, 6, 7, 8, 9})
        std::cout << x << "\n";
    std::cout << std::endl;
    
    std::cout << "Using References in For to get the True Values (not copies) from the array's elements\n";
    // A reference is similar to a pointer, except that you don’t need to use a prefix * to access the
    // value referred to by the reference. Also, a reference cannot be made to refer to a different
    // object after its initialization.
    for (auto& x : v) {
        x++;
        std::cout << x << "\n";
    }
    
    std::cout << "Here, the values of v were changed\n";
    // now, the values of v were changed
    for (auto i = 0; i < 10; i++)
        std::cout << "[" << i << "] = " << v[i] << std::endl;
    std::cout << std::endl;
}

void increment() { 
    int v[] = {0, 1, 2, 3, 4, 5};
    for (auto &x : v)
        ++x;
    std::cout << "\n now value in v[] \n";
    for (auto x : v) {
        std::cout << x << "\n";
    }
}

// count the number of occurrences of x in p[]
// p is assumed to point to 
//a zero-terminated array of char (or to nothing)
int count_x(char* p, char x) { 
    if (p == nullptr) return 0;
    int count = 0;
    for (; p != nullptr; ++p) {
        if (*p == x) { 
            ++count; 
        }
    }
    return count;

}

int main() {
    //print();
    increment();
    return 0;
}

