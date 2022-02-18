#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <limits>
#include <random>


static bool abs_compare(int a, int b) { return (std::abs(a) < std::abs(b)); }


static std::vector<int> generate_data(size_t size) {
    using value_type = int;
    // We use static in order to instantiate the random engine
    // and the distribution once only.
    // It may provoke some thread-safety issues.
    static std::uniform_int_distribution<value_type> distribution(
        std::numeric_limits<value_type>::min(),
        std::numeric_limits<value_type>::max());
    static std::default_random_engine generator;

    std::vector<value_type> data(size);
    std::generate(data.begin(), data.end(),
                  []() { return distribution(generator); });
    return data;
}



int main() {
    std::vector<int>           v{3, 1, -14, 1, 5, 9, 3, 6, 7, 8, 9};
    std::vector<int>         wls{7, 8, -12, 1, 5, 900, 3, 6, 71, 80, 80};
    std::vector<int>::iterator result;
    int                        max_index = 0;
    int                        wls_value;


    result = std::max_element(v.begin(), v.end());    
    //std::cout << "max element at: " << std::distance(v.begin(), result) << '\n';
    max_index = std::distance(v.begin(), result);
    std::cout << "max element at index : " << max_index << '\n';
    //get value from wls
    wls_value = wls.at(max_index);
    std::cout << "wls_value : " << wls_value << '\n';
    result = std::max_element(v.begin(), v.end(), abs_compare);
    std::cout << "max element (absolute) at: "
              << std::distance(v.begin(), result) << '\n';


    //------------------------------------
    /* create a random data */
    const size_t                  n = 100;
    std::vector<double>           spectrum;
    std::vector<double>::iterator max_intensity_val;

    double                                 lower_bound = 0;
    double                                 upper_bound = 10000;
    std::uniform_real_distribution<double> unif(lower_bound, upper_bound);
    std::default_random_engine             re;
    

    spectrum.resize(3648);
    for (int i = 0; i < 100; i++) {
        double a_random_double = unif(re);
        spectrum[i] = a_random_double;
    }

  
    max_intensity_val = std::max_element(spectrum.begin(), spectrum.end());
    //std::cout << "\n max_intensity_val : " << max_intensity_val << '\n';

    int max_intensity_index = std::distance(spectrum.begin(), max_intensity_val);
    std::cout << "\n max_intensity_index : " << max_index << '\n';


 
}