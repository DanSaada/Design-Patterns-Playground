
# Bridge Design Pattern

## Definition:
The Bridge design pattern is a structural design pattern that separates an object's abstraction from its implementation
so that the two can vary independently. It does this by creating a bridge interface that defines the abstraction, and 
then implementing that interface with different concrete classes for various implementations. This allows you to change
or extend both the abstraction and implementation independently without affecting each other.

![image](https://github.com/DanSaada/Design-Patterns-Playground/assets/112869076/2c144bd0-53d5-45dd-9113-2ed05a90b390)


## Advantages:
* Decouples Abstraction and Implementation: The main advantage of the Bridge pattern is that it separates the abstraction and implementation, reducing their interdependence. This makes the system more flexible and easier to maintain because you can change either the abstraction or implementation without affecting the other.
* Enhanced Extensibility: You can add new abstractions or implementations without modifying existing code. This promotes an open-closed principle, making the codebase more extensible.

## Disadvantages:
* Complexity: Implementing the Bridge pattern can introduce additional complexity to the code, especially when dealing with multiple abstractions and implementations.
* Increased Number of Classes: The pattern may require the creation of more classes to manage the abstraction and implementation separately, which can make the codebase larger and potentially harder to understand.

## Code Example:
In this example, we have a bridge between different shapes (Circle and Square) and their colors (Red and Blue). 
The Bridge pattern allows us to change the color or shape independently without modifying the other, demonstrating the separation of abstraction and implementation.


