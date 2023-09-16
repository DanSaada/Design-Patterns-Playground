# Composite Design Pattern

## Definition:
The Composite Pattern is a structural design pattern that allows you to compose objects into tree structures to represent part-whole hierarchies. 
It lets clients treat individual objects and compositions of objects uniformly.

![image](https://github.com/DanSaada/Design-Patterns-Playground/assets/112869076/b993130c-8628-4e03-8528-58493048587a)

## Advantages:
* Uniformity: The Composite Pattern provides a unified way to work with individual objects and compositions of objects. Clients can treat them uniformly through the common interface (Component).
* Flexibility: You can create complex structures by nesting composites within composites, making it easy to add or remove elements without changing the client code.
* Simplified client code: Clients don't need to distinguish between leaf and composite objects, which simplifies the client code.
* Recursive behavior: The pattern naturally supports recursive algorithms, making it suitable for operations that traverse and manipulate the hierarchy.

## Disadvantages:
* Complexity: Implementing the Composite Pattern can make your code more complex, especially if you need to support different types of operations for leaf and composite elements.
* Performance: Depending on how you implement it, the pattern can have performance overhead due to the recursive nature of the structure.

## Code Example:
In this example, we have two types of employees: Developers (Leaf) and Managers (Composite). The Composite Pattern allows us to create a hierarchical organization structure, and the showDetails method can display the details of both individual employees and their managers.

