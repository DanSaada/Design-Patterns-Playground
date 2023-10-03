# Factory Design Pattern

## Definition:
The Factory Design Pattern is one of the creational design patterns in software engineering. 
It provides an interface for creating objects but allows subclasses to alter the type of objects that will be created. 
This pattern abstracts the process of object creation, encapsulating it within a class or a method, and thus promoting loose coupling in your code.

![image](https://github.com/DanSaada/Design-Patterns-Playground/assets/112869076/001c2143-dac9-4d2e-bedc-45062804a961)

## Advantages:
* Encapsulation: It encapsulates object creation within a dedicated method or class, isolating the client code from the details of how objects are created.
* Abstraction: It provides an abstract interface for creating objects, allowing you to work with the interface instead of concrete classes, which makes your code more flexible.
* Subclassing: It allows you to create new subclasses easily without modifying the existing client code. This is particularly useful when you need to add new types of objects without affecting the existing codebase.

## Disadvantages:
* Complexity: In some cases, introducing a Factory can add complexity to your code, especially when there are only a few types of objects to create.
* Increased Code Size: You may end up with more classes (e.g., Concrete Factories, Concrete Products) when using this pattern, which can increase code size.
* Abstraction Overhead: Overusing the Factory pattern can lead to unnecessary levels of abstraction and make the code harder to understand.

## Code Example:
In this example, the ShapeFactory is responsible for creating instances of Shape objects (Circle or Square). 
Clients can request shapes from the factory without knowing the specific implementation details of each shape. 
This demonstrates the Factory Design Pattern's advantages of encapsulation and abstraction.
