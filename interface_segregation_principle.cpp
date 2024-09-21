#include <iostream>

class Worker {
public:
    virtual void work() = 0;
    virtual void eat() = 0;
};

class HumanWorker : public Worker {
public:
    void work() override {
        std::cout << "Human working..." << std::endl;
    }

    void eat() override {
        std::cout << "Human eating..." << std::endl;
    }
};

class RobotWorker : public Worker {
public:
    void work() override {
        std::cout << "Robot working..." << std::endl;
    }

    // This method is not needed for robots, but we are forced to implement it
    void eat() override {
        // Robots don't eat, so we throw an exception or leave it blank
        throw std::logic_error("Robots don't eat!");
    }
};

// Problems with This Code:
// Violation of ISP:
//	   The RobotWorker class is forced to implement the eat() method, which makes no sense for robots.
//	   This leads to either throwing exceptions or leaving the method empty, both of which are bad practices.
// Unnecessary Code:
//	   The Worker interface is too broad, forcing unrelated responsibilities on different
//	   classes. Robots should not be concerned with human-specific methods like eat().


// Interface for work behavior
class Workable {
public:
    virtual void work() = 0;
    virtual ~Workable() = default;
};

// Interface for human needs
class Eatable {
public:
    virtual void eat() = 0;
    virtual ~Eatable() = default;
};

class HumanWorker : public Workable, public Eatable {
public:
    void work() override {
        std::cout << "Human working..." << std::endl;
    }

    void eat() override {
        std::cout << "Human eating..." << std::endl;
    }
};

class RobotWorker : public Workable {
public:
    void work() override {
        std::cout << "Robot working..." << std::endl;
    }
    // No need for an eat() method in RobotWorker
};

// Advantages:
// Interface Segregation:
//	   HumanWorker only implements the Eatable interface because humans need the eat() method,
//	   while RobotWorker implements only the Workable interface, which makes sense for robots.
// No Unnecessary Code:
//	   The RobotWorker class no longer has to implement the eat() method, resulting in cleaner,
//	   more focused code.
// Better Maintainability:
//	   The separation of concerns ensures that changes in one part of the system (e.g., how workers eat)
//	   won’t affect unrelated classes (e.g., robots).
