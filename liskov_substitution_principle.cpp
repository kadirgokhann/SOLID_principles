#include <iostream>

class Bird {
public:
    virtual void fly() {
        std::cout << "Flying..." << std::endl;
    }
};

class Penguin : public Bird {
public:
    void fly() override {
        throw std::logic_error("Penguins can't fly!");
    }
};

void makeBirdFly(Bird& bird) {
    bird.fly();
}

// Problems with This Code:
// Violation of LSP:
// 	 Penguin is a type of Bird, but when it is passed to the makeBirdFly function, it throws an exception
// 		because penguins cannot fly. This violates LSP because substituting a Penguin for a Bird breaks
// 		the behavior of the program.
//   The base class (Bird) assumes that all derived classes can fly, which isn't true for all birds.



// Create a new base class for flight capability
class Bird {
public:
    virtual void eat() {
        std::cout << "Eating..." << std::endl;
    }
    virtual ~Bird() = default;
};

// Create a separate class for birds that can fly
class FlyingBird : public Bird {
public:
    virtual void fly() {
        std::cout << "Flying..." << std::endl;
    }
};

// Penguin class doesn't need to implement flying behavior
class Penguin : public Bird {
public:
    void swim() {
        std::cout << "Swimming..." << std::endl;
    }
};

// Other birds can extend FlyingBird
class Sparrow : public FlyingBird {
public:
    void fly() override {
        std::cout << "Sparrow flying..." << std::endl;
    }
};

void makeBirdFly(FlyingBird& bird) {
    bird.fly();
}

// Advantages:
// LSP Compliant:
//	   Penguin no longer inherits the fly method, avoiding inappropriate behavior when trying to fly.
//	   Now, only birds that can actually fly inherit from FlyingBird, keeping the behavior correct.
// Better Abstraction:
//	   Separating the flying capability from the base Bird class provides better abstraction, allowing
//	   for accurate class hierarchies.
// Correct Substitutability:
//	   A Sparrow can be passed to makeBirdFly() without breaking the program.
//	   A Penguin won’t be incorrectly expected to fly, but can still use other Bird behaviors like eat().
