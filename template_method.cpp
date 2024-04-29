#include <iostream>

class VehicleTemplate {
public:
    void buildVehicle() {
        assembleBody();
        installEngine();
        addWheels();
        std::cout << "Vehicle is ready!" << std::endl;
    }
    virtual void assembleBody() = 0;
    virtual void installEngine() = 0;
    virtual void addWheels() = 0;
};

class Car : public VehicleTemplate {
public:
    void assembleBody() override {
        std::cout << "Assembling car body.\n";
    }
    void installEngine() override {
        std::cout << "Installing car engine.\n";
    }
    void addWheels() override {
        std::cout << "Adding 4 wheels to the car.\n";
    }
};

class Motorcycle : public VehicleTemplate {
public:
    void assembleBody() override {
        std::cout << "Assembling motorcycle frame.\n";
    }
    void installEngine() override {
        std::cout << "Installing motorcycle engine.\n";
    }
    void addWheels() override {
        std::cout << "Adding 2 wheels to the motorcycle.\n";
    }
};

int main() {
    std::cout << "Building a car:\n";
    Car car;
    car.buildVehicle();

    std::cout << "\nBuilding a motorcycle:\n";
    Motorcycle motorcycle;
    motorcycle.buildVehicle();

    return 0;
}