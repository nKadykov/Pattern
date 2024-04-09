#include <iostream>
#include <vector>

enum Vehicle_ID {Truck_ID, Car_ID, Bike_ID};

class Vehicle {
public:
    virtual void info() = 0;
    virtual ~Vehicle() {}
    static Vehicle *createVehicle(Vehicle_ID id);
};

class Truck : public Vehicle {
public:
    void info() {
        std::cout << "Truck" << std::endl;
    }
};

class Car : public Vehicle {
public:
    void info() {
        std::cout << "Car" << std::endl;
    }
};

class Bike : public Vehicle {
public:
    void info() {
        std::cout << "Bike" << std::endl;
    }
};

Vehicle *Vehicle::createVehicle(Vehicle_ID id) {
    Vehicle *vehicle;
    switch(id) {
        case Truck_ID:
            vehicle = new Truck();
            break;
        case Car_ID:
            vehicle = new Car();
            break;
        case Bike_ID:
            vehicle = new Bike();
            break;
    }
    return vehicle;
}

class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing circle" << std::endl;
    }
};

class Square : public Shape {
    void draw() override {
        std::cout << "Drawing square" << std::endl;
    }
};

class ShapeFactory {
public:
    virtual ~ShapeFactory() {}
    virtual Shape* createShape() = 0;
};

class CircleFactory : public ShapeFactory {
public:
    Shape *createShape() override { return new Circle(); }
};

class SquareFactory : public ShapeFactory {
public:
    Shape *createShape() override { return new Square(); }
};

int main() {
    std::vector<Vehicle *> vect;
    vect.push_back(Vehicle::createVehicle(Truck_ID));
    vect.push_back(Vehicle::createVehicle(Car_ID));
    vect.push_back(Vehicle::createVehicle(Bike_ID));

    for(int i = 0; i < vect.size(); i++) {
        vect[i]->info();
    }

    ShapeFactory *circleFactory = new CircleFactory();
    ShapeFactory *squareFactory = new SquareFactory();

    Shape *circle = circleFactory->createShape();
    Shape *square = squareFactory->createShape();

    circle->draw();
    square->draw();

    delete circleFactory;
    delete squareFactory;
    delete circle;
    delete square;

    std::string shapeType;
    std::cin >> shapeType;

    ShapeFactory* shapeFactory = nullptr;
    if(shapeType == "circle") {
        shapeFactory = new CircleFactory();
    }
    else if(shapeType == "square") {
        shapeFactory = new SquareFactory();
    }
    else {
        std::cout << "Invalid shape type entered." << std::endl;
        return 1;
    }

    Shape *shape = shapeFactory->createShape();
    shape->draw();

    delete shapeFactory;
    delete shape;

    return 0;
}