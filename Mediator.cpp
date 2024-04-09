#include <iostream>
#include <string>

class BaseComponent;
class Mediator {
public:
    virtual void Notify(BaseComponent *sender, std::string event) const = 0;
};

class BaseComponent {
protected:
    Mediator *mediator;
public:
    BaseComponent(Mediator *m = nullptr) : mediator(m) {}
    void set_mediator(Mediator *m) {
        this->mediator = m;
    }
};

class Component1 : public BaseComponent {
public:
    void DoA() {
        std::cout << "Component 1 does A.\n";
        this->mediator->Notify(this, "A");
    }
    void DoB() {
        std::cout << "Component 1 does B.\n";
        this->mediator->Notify(this, "B");
    }
};

class Component2 : public BaseComponent {
public:
    void DoC() {
        std::cout << "Component 2 does C.\n";
        this->mediator->Notify(this, "C");
    }
    void DoD() {
        std::cout << "Component 2 does D.\n";
        this->mediator->Notify(this, "D");
    }
};

class ConcreteMediator : public Mediator {
private:
    Component1 *component1;
    Component2 *component2;
public:
    ConcreteMediator(Component1 *c1, Component2 *c2) : component1(c1), component2(c2) {
        this->component1->set_mediator(this);
        this->component2->set_mediator(this);
    }
    void Notify(BaseComponent *sender, std::string event) const override {
        if(event == "A") {
            std::cout << "Mediator reacts on A and triggers following operations:\n";
            this->component2->DoC();
        }
        if(event == "D") {
            std::cout << "Mediator reacts on D and triggers following operations:\n";
            this->component1->DoB();
            this->component2->DoC();
        }
    }
};

void ClientCode() {
    Component1 *c1 = new Component1;
    Component2 *c2 = new Component2;
    ConcreteMediator *mediator = new ConcreteMediator(c1, c2);
    std::cout << "Client triggers operation A.\n";
    c1->DoA();
    std::cout << "\nClient triggers operation D.\n";
    c2->DoD();

    delete c1;
    delete c2;
    delete mediator;
}

int main() {
    ClientCode();
    return 0;
}