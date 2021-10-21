#include "01_vector.h"
#include <list>

int main() {
    Vector<int>v(100);
    v[0] = 10;
    std::cout << "v[0]= " << v[0] << std::endl;

    Vector<char> vc(200); //vector of 200 characters
    vc[0] = 'A';
    std::cout << "CHAR vc[0] = " << vc[0] << std::endl;

    
    Vector<double> vd(200);
    vd[0] = 2.5;
    std::cout << "DOUBLE vd[0] = " << vd[0] << std::endl;
    
    Vector<std::string> vs(17); //vector of 17 string
    vs[0] = "A Tour of C++";
    std::cout << "STRING vs[0] = " << vs[0] << std::endl;

    Vector<std::list<int>> vli(45); // Vector of 45 list of integer
    std::list<int>   test_l = {6, 7, 8, 16, 18};
    //vli[0].push_back(5);
    //vli[0].push_back(7);
    vli[0] = test_l;
    std::cout << "\n ===> Data in list: \n";
    for (int n : vli[0]) {
        std::cout << "vli[0] = "<< n << std::endl;
    }

   
    
    return 0;
}