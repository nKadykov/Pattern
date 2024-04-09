#include <iostream>

class TrafficLightState {
public:
    virtual void handle() = 0;
};

class RedState : public TrafficLightState {
public:
    void handle() override {
        std::cout << "Traffic Light is Red\n";
    }
};

class YellowState : public TrafficLightState {
public:
    void handle() override {
        std::cout << "Traffic Light is Yellow\n";
    }
};

class GreenState : public TrafficLightState {
public:
    void handle() override {
        std::cout << "Traffic Light is Green\n";
    }
};

class TrafficLight {
private:
    TrafficLightState *state;
public:
    TrafficLight() : state(new RedState()) {}
    void setState(TrafficLightState *newState) {
        delete state;
        state = newState;
    }
    void change() {
        state->handle();
    }
};

int main() {
    TrafficLight trafficLight;

    trafficLight.change();
    trafficLight.setState(new GreenState());
    trafficLight.change();

    return 0;
}