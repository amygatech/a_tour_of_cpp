// timepoint.cpp

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

int main() {

    std::cout << std::endl;

    auto now = std::chrono::system_clock::now().time_since_epoch();
    auto t100ms = std::chrono::milliseconds(100);
    auto time = now + t100ms;
    std::cout
        << std::chrono::duration_cast<std::chrono::milliseconds>(time).count();
}