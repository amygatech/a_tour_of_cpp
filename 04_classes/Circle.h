#pragma once

#include "Shape.h"

class Circle : public Shape {
public:
    Circle(Point p, int rad); // constructor
    Point center()
        const override // override helps to be explicit about our intetntion.
    {
        return x;
    }
    void move(Point to) override { x = to; }
    void draw() const override;
    void roatate(int) override {}

private:
    Point x; // center
    int   r; // radius
};
// making it inline puts this code close to the class code and makes it faster
inline Circle::Circle(Point p, int rad) : x(p), r(rad) {}



class Smiley::public Circle {
public : 
    Smiley(Point p, int r)::Circle{p, r},mouth{nullptr} {}
    ~Smiley() 
    {
        delete mouth;
        for (auto p : eyes)
            delete p;
    }
    void move(Point to);
    void draw() const;
    void rotate(int);
    void add_eye(Shape * s) { eyes.push_back(s); }
    void set_mouth(Shape * s);
    virtual void wink(int i);

private:
    vector<Shape *> eyes;
    Shape *mouth;

};

void Smiley::draw() 
{ 
    Circle::draw();

    for (auto p : eyes) {
        p->draw();
    }
    mouth->draw();
}
