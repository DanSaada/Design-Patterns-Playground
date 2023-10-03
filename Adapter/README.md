# Adapter Design Pattern

## Definition:
The Adapter design pattern is a structural design pattern that allows objects with incompatible interfaces to work together. 
It acts as a bridge between two incompatible interfaces, making them compatible without changing their source code. 
This pattern is useful when you have existing classes or components that cannot be easily modified to work with each other due to their differing interfaces.

![image](https://github.com/DanSaada/Design-Patterns-Playground/assets/112869076/961503ed-a6f3-41b9-bf52-6f350748794c)

## Advantages:
* Compatibility: It allows objects with incompatible interfaces to work together, promoting reusability of existing code.
* Separation of Concerns: It separates the client code from the complex or legacy code, improving code maintainability and readability.
* Open/Closed Principle: It follows the open/closed principle of the SOLID principles, allowing you to add new Adapters without modifying existing code.

## Disadvantages:
* Complexity: If there are many Adapters and interfaces to manage, it can increase the complexity of the codebase.
* Performance Overhead: There may be a slight performance overhead due to the additional layer of indirection introduced by the Adapter.

## Code Example:
In this example, the LegacyPrinterAdapter allows the legacy LegacyPrinter to be used as a modern Printer. 
It adapts the print() method to call printDocument() internally and adds a new scan() method to fulfill the Printer interface.
