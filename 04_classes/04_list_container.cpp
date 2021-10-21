#include <iostream>
#include "vector_container.h"
#include "list_container.h"

#include <stdexcept> // std::out_of_range

// cannot override in the implementation, only in the definition
double &ListContainer::operator[](int i) {
    for (auto &x : ld) {
        if (i == 0) return x;
        --i;
    }
    throw std::out_of_range{"List Container"};
}


void use(Container &c) {
    std::cout << "using\n";
    for (long i = 0; i < c.size(); i++)
        std::cout << "[" << i << "] = " << c[i] << std::endl;

    c.xpto(); // it always calls the 'xpto' of Container because it is not
              // virtual.
    std::cout << "\n";
}

void useListContainer() {
    std::cout << "useListContainer\n";

    ListContainer lc = {0, 1, 2, 3, 4};
    use(lc);
}

int main() {
    useListContainer();

    return 0;
}