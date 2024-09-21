# SOLID Principles Summary

## 1. Single Responsibility Principle (SRP)
Each class should have **one and only one reason to change**, meaning it should have only one job or responsibility. This makes classes easier to maintain and less prone to bugs.

**Example**: Separating report generation, saving, and printing functionalities into different classes.

## 2. Open/Closed Principle (OCP)
Software entities (classes, functions, etc.) should be **open for extension** but **closed for modification**. This allows you to add new features without changing existing code, reducing the risk of introducing bugs.

**Example**: Adding new shapes (like `Triangle`) without modifying the shape calculator by using a common `Shape` interface.

## 3. Liskov Substitution Principle (LSP)
Subtypes must be substitutable for their base types without affecting the correctness of the program. Derived classes must not break the parent class’s expectations.

**Example**: Creating a separate `FlyingBird` class for birds that can fly, ensuring that `Penguin` (which can't fly) doesn't violate this principle.

## 4. Interface Segregation Principle (ISP)
Clients should not be forced to depend on interfaces they do not use. Instead of large interfaces, create smaller, more specific ones.

**Example**: Splitting the `Worker` interface into `Workable` and `Eatable`, so robots are not forced to implement an unnecessary `eat()` method.

## 5. Dependency Inversion Principle (DIP)
High-level modules should not depend on low-level modules. Both should depend on abstractions. Also, abstractions should not depend on details; details should depend on abstractions.

**Example**: Using a `Switchable` interface so that `Switch` is not directly dependent on specific light implementations like `LightBulb` or `LEDLight`.

---

This summary provides a concise overview of each SOLID principle, demonstrating the problems with violating each and the benefits of applying them.
