
# Builder Design Pattern

## Definition:
The Builder design pattern is a creational pattern that separates the construction 
of a complex object from its representation, allowing the same construction process 
to create different representations. 
It is useful when you have a complex object with many optional parameters or configurations.

![image](https://github.com/DanSaada/Design-Patterns-Playground/assets/112869076/62e6a4b6-f8c3-46cf-890f-1ab697691151)

## Advantages:
* Allows you to vary a product's internal representation.
* Encapsulates code for construction and representation.
* Provides control over steps of construction process.

## Disadvantages:
* A distinct ConcreteBuilder must be created for each type of product.
* Builder classes must be mutable.
* May hamper/complicate dependency injection.

## Code Example:
This code demonstrates how the Builder design pattern can be used to create Computer objects 
with flexible configuration options, allowing for easy construction of complex objects with 
various specifications.


