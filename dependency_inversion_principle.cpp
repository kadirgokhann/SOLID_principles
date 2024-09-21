#include <iostream>

// Low-level module
class LightBulb {
public:
    void turnOn() {
        std::cout << "LightBulb is on." << std::endl;
    }
    void turnOff() {
        std::cout << "LightBulb is off." << std::endl;
    }
};

// High-level module
class Switch {
    LightBulb& bulb;
public:
    Switch(LightBulb& lb) : bulb(lb) {}

    void operate(bool on)
	{
        if (on) {
            bulb.turnOn();
        } else {
            bulb.turnOff();
        }
    }
};

// Problems with This Code:
// Violation of DIP:
//	   The Switch class (high-level module) directly depends on the LightBulb class
//	   (low-level module). If we want to change the type of lighting (e.g., to a LEDLight),
//	   we need to modify the Switch class.
// Tight Coupling:
//	   The system is tightly coupled, making it harder to extend or modify. If we add new types
//	   of lights, we’ll have to rewrite or modify the Switch class.


// Abstraction (Interface)
class Switchable {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual ~Switchable() = default;
};

// Low-level module
class LightBulb : public Switchable {
public:
    void turnOn() override {
        std::cout << "LightBulb is on." << std::endl;
    }
    void turnOff() override {
        std::cout << "LightBulb is off." << std::endl;
    }
};

// Low-level module
class LEDLight : public Switchable {
public:
    void turnOn() override {
        std::cout << "LEDLight is on." << std::endl;
    }
    void turnOff() override {
        std::cout << "LEDLight is off." << std::endl;
    }
};

// High-level module depends on the abstraction, not the concrete class
class Switch {
    Switchable& device;
public:
    Switch(Switchable& s) : device(s) {}

    void operate(bool on) {
        if (on) {
            device.turnOn();
        } else {
            device.turnOff();
        }
    }
};

// Advantages:
// Inversion of Dependency:
//	   The Switch class now depends on the Switchable interface (abstraction), not the concrete class
//	   (LightBulb or LEDLight). This makes the high-level module (Switch) independent of the low-level
//	   module (LightBulb or LEDLight).
// Easily Extensible:
//	   We can now add any new light type (e.g., FluorescentLight) without changing the Switch class.
//	   All new lights just need to implement the Switchable interface.
// Decoupling:
//	   By decoupling the high-level and low-level modules, the system becomes easier to maintain, test, and extend.
