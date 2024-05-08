#include <iostream>
#include <string>
#include <unordered_map>

enum Type {
    PROTOTYPE_1 = 0,
    PROTOTYPE_2
};

class Prototype {
public:
    Prototype() {}
    Prototype(std::string prototype_name) : m_prototype_name(prototype_name) {}
    virtual ~Prototype() {}
    virtual Prototype *Clone() const = 0;
    virtual void Method(float prototype_field) {
        this->m_prototype_field = prototype_field;
        std::cout << "Call Method from " << m_prototype_name << " with field: " << prototype_field << std::endl;
    }
protected:
    std::string m_prototype_name;
    float m_prototype_field;
};

class ConcretePrototype1 : public Prototype {
public:
    ConcretePrototype1(std::string prototype_name, float concrete_prototype_field) : Prototype(prototype_name), m_concrete_prototype_field1(concrete_prototype_field) {}
    Prototype* Clone() const override {
        return new ConcretePrototype1(*this);
    }
private:
    float m_concrete_prototype_field1;
};

class ConcretePrototype2 : public Prototype {
public:
    ConcretePrototype2(std::string prototype_name, float concrete_prototype_field) : Prototype(prototype_name), m_concrete_prototype_field2(concrete_prototype_field) {}
    Prototype* Clone() const override {
        return new ConcretePrototype2(*this);
    }
private:
    float m_concrete_prototype_field2;
};

class PrototypeFactory {
public:
    PrototypeFactory() {
        m_prototype[Type::PROTOTYPE_1] = new ConcretePrototype1("PROTOTYPE_1", 50.0f);
        m_prototype[Type::PROTOTYPE_2] = new ConcretePrototype2("PROTOTYPE_2", 60.0f);
    }
    ~PrototypeFactory() {
        delete m_prototype[Type::PROTOTYPE_1];
        delete m_prototype[Type::PROTOTYPE_2];
    }
    Prototype* CreatePrototype(Type type) {
        return m_prototype[type]->Clone();
    }
private:
    std::unordered_map<Type, Prototype*, std::hash<int>> m_prototype;
};

void Client(PrototypeFactory& prototype_factory) {
    std::cout << "Let's create a Prototype 1\n";

    Prototype* prototype = prototype_factory.CreatePrototype(Type::PROTOTYPE_1);
    prototype->Method(90);
    delete prototype;

    std::cout << "\n";

    std::cout << "Let's create a Prototype 2\n";

    prototype = prototype_factory.CreatePrototype(Type::PROTOTYPE_2);
    prototype->Method(10);

    delete prototype;
}

int main() {
    PrototypeFactory* prototype_factory = new PrototypeFactory();
    Client(*prototype_factory);
    delete prototype_factory;

    return 0;
}