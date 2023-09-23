#include <iostream>
#include <string>

using namespace std;

// Implementor interface
class ColorImplementor {
public:
    virtual string fillColor() = 0;
};

// Concrete Implementors
class RedColor : public ColorImplementor {
public:
    string fillColor() override {
        return "Red";
    }
};

class BlueColor : public ColorImplementor {
public:
    string fillColor() override {
        return "Blue";
    }
};

// Abstraction
class Shape {
protected:
    ColorImplementor* color_impl;

public:
    Shape(ColorImplementor* impl) : color_impl(impl) {}

    virtual void draw() = 0;
};

// Concrete Abstractions
class Circle : public Shape {
public:
    Circle(ColorImplementor* impl) : Shape(impl) {}

    void draw() override {
        cout << color_impl->fillColor() << " Circle" << endl;
    }
};

class Square : public Shape {
public:
    Square(ColorImplementor* impl) : Shape(impl) {}

    void draw() override {
        cout << color_impl->fillColor() << " Square" << endl;
    }
};

int main() {
    ColorImplementor* redImpl = new RedColor();
    ColorImplementor* blueImpl = new BlueColor();

    Shape* redCircle = new Circle(redImpl);
    Shape* blueSquare = new Square(blueImpl);

    redCircle->draw();   // Output: "Red Circle"
    blueSquare->draw();  // Output: "Blue Square"

    delete redImpl;
    delete blueImpl;
    delete redCircle;
    delete blueSquare;

    return 0;
}
