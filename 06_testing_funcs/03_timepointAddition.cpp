// timepointAddition.cpp

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

//using namespace std::chrono;

// get date as YYYYMMDD
std::string getCurrentDate() {
    std::time_t now =
        std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    char buf[100] = {0};
    //std::strftime(buf, sizeof(buf), "%Y-%m-%d", std::localtime(&now));
    std::strftime(buf, sizeof(buf), "%Y%m%d", std::localtime(&now));
    return buf;
}

std::string timePointAsString(
    const std::chrono::time_point<std::chrono::system_clock> &timePoint) {
    std::time_t tp = std::chrono::system_clock::to_time_t(timePoint);
    return std::asctime(std::gmtime(&tp));
}

int main() {

    std::cout << std::endl;

    auto str_time = getCurrentDate();
    std::cout << "The string time is " << str_time.c_str() << std::endl;

    std::chrono::time_point<std::chrono::system_clock> nowTimePoint =
        std::chrono::system_clock::now();
    std::cout << "Now:              " << timePointAsString(nowTimePoint)
              << std::endl;

    int                      shot_time = 5; //5s
    std::chrono::time_point<std::chrono::system_clock> futureTimePoint =
        nowTimePoint + std::chrono::seconds(shot_time);
    std::cout << "Now + 5s: " << timePointAsString(futureTimePoint)
              << std::endl;

    for (;;) {

        std::chrono::time_point<std::chrono::system_clock> current_time =
            std::chrono::system_clock::now();
        std::cout << "current_time:              "
                  << timePointAsString(current_time)
                  << std::endl;

        std::cout << "futureTimePoint:              "
                  << timePointAsString(futureTimePoint) << std::endl;

        if (current_time < futureTimePoint) {
            printf("\n inside compare time \n ");
        } 
        else {
            printf("\n === COMPLETE TIMER ==========");
            break;
        }
    }

    return 0;
}