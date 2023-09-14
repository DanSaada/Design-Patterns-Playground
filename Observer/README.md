#  Design Pattern

## Definition:
The Observer design pattern is a behavioral pattern that defines a one-to-many dependency 
between objects so that when one object (the subject) changes state, all its dependents 
(observers) are notified and updated automatically. This pattern is useful for building 
systems where the state of one object needs to be reflected in the state of other objects.

<img width="500" height="400" alt="Design-Patterns-Playground-Logo" src="https://github.com/DanSaada/Design-Patterns-Playground/assets/112869076/88636f9d-ebf7-44fe-829b-2131ff660560">

## Advantages:
* Loose Coupling: Promotes a loosely coupled relationship between objects, making it easier to change or add observers without affecting the subject.
* Flexibility: Allows multiple observers to react to state changes in a subject independently, enabling a more flexible and extensible system.
* Notification Control: Subjects only notify observers when relevant changes occur, reducing unnecessary updates and improving efficiency.

## Disadvantages:
* Complexity: Can lead to increased complexity, especially when dealing with a large number of observers or intricate notification logic.
* Memory Management: Care must be taken to manage references between subjects and observers to avoid memory leaks.
* Ordering Issues: The order in which observers are notified may not always be predictable, potentially causing issues in some scenarios.

## Code Example:
In this code, the Observer pattern is applied by creating a relationship between a subject 
(Moodle) and one or more observers (Student). Observers are notified whenever the subject's 
state (course scores) changes. This allows the Student observer to react to changes in the 
"algo" course score, demonstrating the decoupling of the subject and observer. This pattern 
is useful for scenarios where multiple objects need to stay synchronized with the state of 
a single object.
