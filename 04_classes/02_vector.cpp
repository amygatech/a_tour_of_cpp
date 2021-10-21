
#include "vector.h"

int main() {
    Vector v(5);
    
    for (long i = 0; i < v.size(); i++)
        v[i] = i;
    
    std::cout << "\n The inital v data: \n";
    v.print();
    
    try {
        for (long i = 0; i < v.size(); i++)
            //v.at(i * 10) = i;
            v.at(i * 2) = i;
    }
    catch (std::out_of_range& err) { // oops: out_of_range error
        std::cout << "Error caught\n";
        std::cerr << err.what() << '\n';
    }
    // we don't need using err
    catch (std::bad_alloc&) { // Ouch! this program is not designed to handle memory exhaustion
        std::terminate(); // terminate the program
    }
    
    std::cout << "\n ===> AFTER v data: \n";
    v.print();
    

    // Another test
    Vector v2 = {0.5, 1.5, 2.5, 3.5};
    v2.print();

    
    return 0;
}