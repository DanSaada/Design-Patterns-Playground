#include <iostream>

// Abstract Shape class (interface)
class Shape {
public:
    virtual void draw() = 0;
};

// Concrete Circle class
class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a Circle." << std::endl;
    }
};

// Concrete Square class
class Square : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a Square." << std::endl;
    }
};

// Shape Factory
class ShapeFactory {
public:
    // Factory method to create Shape objects
    Shape* createShape(const std::string& shapeType) {
        if (shapeType == "circle") {
            return new Circle();
        } else if (shapeType == "square") {
            return new Square();
        }
        return nullptr; // Return nullptr for unsupported types
    }
};

int main() {
    ShapeFactory factory;

    Shape* circle = factory.createShape("circle");
    Shape* square = factory.createShape("square");

    circle->draw(); // Output: Drawing a Circle.
    square->draw(); // Output: Drawing a Square.

    // Don't forget to clean up the allocated memory
    delete circle;
    delete square;

    return 0;
}
