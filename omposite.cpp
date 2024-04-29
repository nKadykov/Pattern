#include <iostream>
#include <vector>
#include <assert.h>

class Unit {
public:
    virtual int getStrength() = 0;
    virtual void addUnit(Unit *p) {
        assert(false);
    }
    virtual ~Unit() {}
};

class Archer : public Unit {
public:
    virtual int getStrength() {
        return 1;
    }
};

class Infantryman : public Unit {
public:
    virtual int getStrength() {
        return 2;
    }
};

class Horseman : public Unit {
public:
    virtual int getStrength() {
        return 3;
    }
};

class CompositeUnit : public Unit {
public:
    int getStrength() {
        int total = 0;
        for(int i = 0; i < c.size(); ++i) {
            total += c[i]->getStrength();
        }
        return total;
    }
    void addUnit(Unit *p) {
        c.push_back(p);
    }
    ~CompositeUnit() {
        for(int i = 0; i < c.size(); ++i) {
            delete c[i];
        }
    }
private:
    std::vector<Unit *> c;
};

CompositeUnit *createLegion() {
    CompositeUnit *legion = new CompositeUnit;
    for(int i = 0; i < 3000; ++i) {
        legion->addUnit(new Infantryman);
    }
    for(int i = 0; i < 1200; ++i) {
        legion->addUnit(new Archer);
    }
    for(int i = 0; i < 300; ++i) {
        legion->addUnit(new Horseman);
    }
    return legion;
}

int main() {
    CompositeUnit *army = new CompositeUnit;
    for(int i = 0; i < 4; i++) {
        army->addUnit(createLegion());
    }
    std::cout << "Roman army damaging strength is " << army->getStrength() << std::endl;
    delete army;
    return 0;
}