# Decorator Design Pattern

## Definition:
The Decorator design pattern is a structural design pattern that allows you to dynamically add or extend behavior to individual objects, either statically or at runtime, without altering their code. 
It is part of the Gang of Four (GoF) design patterns and is commonly used in object-oriented programming to achieve flexibility and modularity in software design.

![image](https://github.com/DanSaada/Design-Patterns-Playground/assets/112869076/23bed84d-94d1-4489-8ea4-6b8ea3e87e67)

## Advantages:
* Open/Closed Principle: The Decorator pattern follows the Open/Closed Principle, allowing you to add new functionality to objects without altering their existing code.
* Flexibility: You can mix and match decorators to create different combinations of functionality, making it highly flexible and customizable.
* Single Responsibility Principle: Each decorator has a single responsibility, making the code easier to maintain and understand.

## Disadvantages:
* Complexity: Overuse of decorators can lead to a complex class hierarchy, making the code harder to understand and maintain.
* Runtime Overhead: Adding multiple decorators at runtime can introduce some performance overhead due to the extra method calls.
* Ordering: The order in which decorators are applied can be crucial. Changing the order may lead to different results.
* 
## Code Example:
In this example, Coffee is the ConcreteComponent, CoffeeDecorator is the Decorator, and MilkDecorator and SugarDecorator are ConcreteDecorators. 
You can create various combinations of coffee with different toppings using decorators without modifying the Coffee class itself.
