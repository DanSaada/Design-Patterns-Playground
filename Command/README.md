# Command Design Pattern

## Definition:
The Command Design Pattern is a behavioral design pattern that encapsulates a request as an object, 
thereby allowing for parameterization of clients with queues, requests, and operations. It allows you 
to parameterize objects with different requests, delay or queue a request's execution, and support 
undoable operations.

<img width="700" height="300" alt="Design-Patterns-Playground-Logo" src="https://github.com/DanSaada/Design-Patterns-Playground/assets/112869076/301f08b6-986e-4d8c-bb45-9acf16524617">

## Advantages:
* Decoupling: It decouples the sender (Client) from the receiver (Receiver) and allows you to change or extend the behavior of the system without affecting other parts of the code.
* Undo/Redo: Since commands are encapsulated as objects, it's easy to implement undo and redo functionality by keeping a history of executed commands.
* Composite Commands: You can create composite commands by combining multiple simple commands into a single, more complex command.

## Disadvantages:
* Increased Complexity: Implementing the Command Pattern can introduce additional classes and interfaces, which can increase the complexity of your codebase. This complexity can make the code harder to understand, especially for simple operations.
* Memory Overhead: Each command typically requires the creation of a separate command object. In systems with a large number of commands, this can lead to increased memory usage.
* Potential for Command Proliferation: If not managed properly, you may end up with a large number of command classes, each representing a different operation. This proliferation of command classes can be challenging to maintain and navigate.

## Code Example:
Overall, this example follows the Command Design Pattern by encapsulating requests (commands) as objects, decoupling the sender (remote control) from the receiver (light), and allowing for parameterization of objects with operations. This pattern also supports undo/redo functionality, as you can store and execute a history of commands.
