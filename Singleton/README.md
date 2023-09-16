# Singleton Design Pattern

## Definition:
The Singleton design pattern is a creational design pattern that ensures a class has 
only one instance and provides a global point of access to that instance. This means that 
no matter how many times you request an instance of the Singleton class, you will always 
get the same instance.

![image](https://github.com/DanSaada/Design-Patterns-Playground/assets/112869076/cbcea6c0-5ec3-4b7a-b97d-52699abf27d9)

## Advantages:
* Single Instance: Ensures a class has only one instance globally, useful for managing shared resources or settings.
* Lazy Initialization: Allows for deferred creation of the instance until it's actually needed, saving resources.

## Disadvantages:
* Global State: Can introduce global state into an application, making it harder to manage and test.
* Thread Safety: Requires special handling to ensure thread safety when multiple threads access the instance concurrently, which can add complexity.

## Code Example:
In the provided example, the Singleton pattern ensures that there is a single instance 
of the Spaceship class, and this instance is created on-demand when you call getSpaceship. 
It allows you to share and reuse this instance across different parts of your code, ensuring
consistency and preventing multiple instances of Spaceship from being created accidentally.
