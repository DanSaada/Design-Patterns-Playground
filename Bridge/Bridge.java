// Implementor interface
interface ColorImplementor {
    String fillColor();
}

// Concrete Implementors
class RedColor implements ColorImplementor {
    public String fillColor() {
        return "Red";
    }
}

class BlueColor implements ColorImplementor {
    public String fillColor() {
        return "Blue";
    }
}

// Abstraction
abstract class Shape {
    protected ColorImplementor colorImpl;

    public Shape(ColorImplementor impl) {
        colorImpl = impl;
    }

    public abstract void draw();
}

// Concrete Abstractions
class Circle extends Shape {
    public Circle(ColorImplementor impl) {
        super(impl);
    }

    public void draw() {
        System.out.println(colorImpl.fillColor() + " Circle");
    }
}

class Square extends Shape {
    public Square(ColorImplementor impl) {
        super(impl);
    }

    public void draw() {
        System.out.println(colorImpl.fillColor() + " Square");
    }

    public static void main(String[] args) {
        ColorImplementor redImpl = new RedColor();
        ColorImplementor blueImpl = new BlueColor();

        Shape redCircle = new Circle(redImpl);
        Shape blueSquare = new Square(blueImpl);

        redCircle.draw();   // Output: "Red Circle"
        blueSquare.draw();  // Output: "Blue Square"
    }
}
