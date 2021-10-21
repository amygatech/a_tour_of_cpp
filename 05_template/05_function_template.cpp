#include <iostream>
#include <stdexcept> // std::length_error
#include <algorithm> // std::copy

#include <list>   // STL list
#include <vector> // STL vector

using std::cout;
using std::endl;


template <typename T> 
class Vector {
private:
    int size_ = 0;
    T * elem_ = nullptr;

public:
    Vector(std::initializer_list<T> lst)
        : elem_{new T[lst.size()]}, size_{static_cast<int>(lst.size())} {
        cout << "initializer-list constructor for Vector\n";

        std::copy(lst.begin(), lst.end(), elem_);
    }

    ~Vector() { delete[] elem_; }


    // without this version, const objects could modify the internal data.
    const T *begin() const {
        cout << "const T* begin() const\n";
        return size_ ? &elem_[0]
                     : nullptr; // pointer to first element or nullptr
    }

    // iterators
    const T *end() const {
        cout << "const T* end() const\n";
        return size_ ? &elem_[size_]
                     : nullptr; // pointer to one-past-last element (next
                                // address after the last element)
    }


    // We do not have a setters for size, because this is non-sense and
    // dangerous. The user could change the size of the Vector (i.e., its
    // private data member size), but its array has a different number of
    // elements allocated.
    int size() const { return size_; }

};




// Container should be a container with range-for implemented
// The Value template argument and the function argument v are there to allow
// the caller to specify the type and initial value of the accumulator (the
// variable in which to accumulate the sum): Note that when callind sum, a copy
// is passed to v, not its reference. Then, we can edit v without changing its
// original value out of the function.
template <typename Container, typename Value>
Value sum(const Container &s, Value v) 
{
    for (const auto x : s)
        v += x;
    return v;
}

int main() {
    std::cout << "v1\n";
    Vector<int> v1{1, 2, 3};
    //int         sum_v1 = sum(v1, 0);
    //std::cout << "sum = " << sum_v1 << "\n\n";
    
   Vector<int> vi{1, 2, 7};
   std::cout << "sum(vi, 0) = " << sum(vi, 0) << "\n\n";

   Vector<double> vd{2.5, 4.5, 3.0};
   cout << "sum(vd, 0.0) = " << sum(vd, 0.0) << "\n\n";

   std::vector<int> vstl = {3, 5, 2};
   cout << "sum(vstl, 0) = " << sum(vstl, 0) << "\n\n";

   std::list<double> lstl = {1.2, 1.8, 7.9};
   cout << "sum(lstl, 0.0) = " << sum(lstl, 0.0) << "\n";

    return 0;
}