#include <iostream>

class Engine {
public:
    void start() {
        std::cout << "Engine started" << std::endl;
    }
    void stop() {
        std::cout << "Engine stopped" << std::endl;
    }
};

class Lights {
public:
    void turnOn() { 
        std::cout << "Lights on" << std::endl; 
    }
    void turnOff() {
        std::cout << "Lights off" << std::endl;
    }
};

class Car {
private:
    Engine engine;
    Lights lights;
public:
    void startCar() {
        engine.start();
        lights.turnOn();
        std::cout << "Car is ready to drive" << std::endl;
    }
    void stopCar() {
        lights.turnOff();
        engine.stop();
        std::cout << "Car has stopped" << std::endl;
    }
};

int main() {
    Car car;
    car.startCar();
    car.stopCar();
    return 0;
}