#include <iostream>
using namespace std;

enum class Traffic_Light { green, yellow, red };

Traffic_Light& operator++ (Traffic_Light& t) { //prefix increament ++
    switch (t) {
        case Traffic_Light::green: {
            cout << "==>Traffic yellow \n";
            return t = Traffic_Light::yellow;
        }
        case Traffic_Light::yellow: {
            cout << "==>Traffic red \n";
            return t = Traffic_Light::red;
        } 
        case Traffic_Light::red: {
            cout << "==>Traffic green \n";
            return t = Traffic_Light::green;
        }
        default: {
            cout << "\n Invalid light- return red \r\n"; 
            return t = Traffic_Light::red;
        }
    }//end, switch

   
}

void trafficMovement(Traffic_Light &t) {
    if (t == Traffic_Light::red) {
        cout << "Traffic Stop\n";
    } else if (t == Traffic_Light::yellow) {
        cout << "Traffic Wait\n";
    } else if (t == Traffic_Light::green) {
        cout << "Traffic Move\n";
    }
}

int main() {
    Traffic_Light t = Traffic_Light::green;
    // traffic movement based on enum Traffic_Light
    trafficMovement(t);

    cout << "\r\n test prefix increment \r\n";
    Traffic_Light next = ++t;

    return 0;
}