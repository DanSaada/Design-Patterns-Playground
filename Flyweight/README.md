# Flyweight Design Pattern

## Definition:
The Flyweight design pattern is a structural design pattern that is used to optimize the memory usage or resource consumption of an application by sharing as much as possible between multiple objects. 
It is particularly useful when you have a large number of similar objects in your application and want to reduce the overhead associated with storing redundant data.
The Flyweight pattern divides objects into two parts: intrinsic and extrinsic.

* Intrinsic State: This is the part of an object that can be shared among multiple objects and is independent of the object's context. Intrinsic state is typically immutable. It is stored in a separate data structure (e.g., a shared pool) and is shared among multiple objects. This reduces memory consumption.
* Extrinsic State: This is the part of an object that depends on the object's context and cannot be shared. It is typically stored outside the Flyweight objects.

![image](https://github.com/DanSaada/Design-Patterns-Playground/assets/112869076/8fa2b719-0111-4382-b2c7-8cb481d92985)

## Advantages:
* Memory Optimization: The primary advantage of the Flyweight pattern is that it reduces memory usage by sharing common intrinsic state among multiple objects. This is especially valuable when dealing with a large number of objects.
* Improved Performance: By sharing common state, the pattern can improve the performance of the application, as it reduces the overhead of creating and managing a large number of similar objects.

## Disadvantages:
* Complexity: Implementing the Flyweight pattern can introduce some complexity into the code, as it requires separating the intrinsic and extrinsic state and managing the shared pool of Flyweight objects.
* Not Suitable for All Situations: The Flyweight pattern is most effective when you have a large number of objects with significant shared state. In some cases, the overhead of managing the shared state may outweigh the benefits.

## Code Example:
In this example,
we have a MusicalNote interface with a play method for playing musical notes with a specified duration.
ConcreteMusicalNote represents the concrete Flyweight objects, which store the intrinsic state (the musical note) and implement the play method to play notes using the shared intrinsic state and the provided duration.
MusicalNoteFactory is responsible for creating and managing Flyweight objects. It maintains a pool of Flyweights based on the intrinsic state (musical notes) and provides them to clients.
In the main method, we simulate a music player that plays a melody by iterating through an array of musical notes. The Flyweight pattern ensures that musical notes with the same symbol are shared and reused, optimizing memory usage.
