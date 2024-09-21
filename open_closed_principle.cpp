#include <iostream>

class Rectangle
{
public:
    float width;
    float height;

    Rectangle(float w, float h) : width(w), height(h) {}

    float area() {
        return width * height;
    }
};

class Circle {
public:
    float radius;

    Circle(float r) : radius(r) {}

    float area() {
        return 3.14159 * radius * radius;
    }
};

class AreaCalculator {
public:
    float calculateTotalArea(Rectangle& rectangle, Circle& circle) {
        return rectangle.area() + circle.area();
    }
};

//  Violation of OCP:
//	If a new shape (e.g., Triangle, Square, etc.) needs to be added, the AreaCalculator class would have to be
//		modified to handle the new shape.
//  This causes the class to be tightly coupled to specific types of shapes, which makes it harder to maintain
// 		and extend



// Abstract base class
class Shape {
public:
    virtual float area() const = 0; // Pure virtual function
    virtual ~Shape() = default; // Virtual destructor for polymorphism
};

class Rectangle : public Shape {
public:
    float width;
    float height;

    Rectangle(float w, float h) : width(w), height(h) {}

    float area() const override {
        return width * height;
    }
};

class Circle : public Shape {
public:
    float radius;

    Circle(float r) : radius(r) {}

    float area() const override {
        return 3.14159 * radius * radius;
    }
};

// New shape can be added without modifying the existing classes
class Triangle : public Shape {
public:
    float base;
    float height;

    Triangle(float b, float h) : base(b), height(h) {}

    float area() const override {
        return 0.5 * base * height;
    }
};

class AreaCalculator {
public:
    float calculateTotalArea(const Shape& shape1, const Shape& shape2) {
        return shape1.area() + shape2.area();
    }
};


// Advantages:
// Open for Extension:
//	   We can add new shapes like Triangle or Square without modifying the AreaCalculator class or the existing
//	       Shape classes.
//	   Adding new functionality just requires extending the Shape base class, adhering to the OCP.
// Closed for Modification:
//	   The AreaCalculator class remains unchanged as new shapes are added. We only extend by
//	        creating new subclasses.
// Better Maintainability:
//	   Less risk of introducing bugs since existing classes aren't modified when adding new functionality.
