// Abstract Shape interface
interface Shape {
    void draw();
}

// Concrete Circle class
class Circle implements Shape {
    @Override
    public void draw() {
        System.out.println("Drawing a Circle.");
    }
}

// Concrete Square class
class Square implements Shape {
    @Override
    public void draw() {
        System.out.println("Drawing a Square.");
    }
}

// Shape Factory
class ShapeFactory {
    // Factory method to create Shape objects
    public Shape createShape(String shapeType) {
        if (shapeType.equalsIgnoreCase("circle")) {
            return new Circle();
        } else if (shapeType.equalsIgnoreCase("square")) {
            return new Square();
        }
        return null; // Return null for unsupported types
    }
}

public class FactoryPatternExample {
    public static void main(String[] args) {
        ShapeFactory factory = new ShapeFactory();

        Shape circle = factory.createShape("circle");
        Shape square = factory.createShape("square");

        circle.draw(); // Output: Drawing a Circle.
        square.draw(); // Output: Drawing a Square.
    }
}
