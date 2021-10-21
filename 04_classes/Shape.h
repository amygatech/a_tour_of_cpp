#pragma once
#include <utility>
#include <vector>

typedef unsigned              uint;
typedef std::pair<uint, uint> Point;

class Shape {
public:
    virtual Point center() const = 0;
    virtual void  move(Point to) = 0;
    virtual void  draw() const = 0;
    virtual void  roatate(int angle) = 0;
    virtual ~Shape(){};
};

//Rotate V's elements by angle degrees.
void roatateAll(std::vector<Shape *> &v, int angle) {
    for (auto p : v) {
        p->roatate(angle);
    }
}