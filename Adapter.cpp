#include <iostream>

class LegacyPrinter {
public:
    void printInUppercase(const std::string &text) {
        std::cout << "Printing: " << text << std::endl;
    }
};

class ModernComputer {
public:
    void sendCommand(const std::string &command) {
        std::cout << "Sending command: " << command << std::endl;
    }
};

class PrinterAdapter {
private:
    LegacyPrinter legacyPrinter;
public:
    void sendCommand(const std::string &command) {
        std::string uppercaseCommand = command;
        for(char &c : uppercaseCommand) {
            c = std::toupper(c);
        }
        legacyPrinter.printInUppercase(uppercaseCommand);
    }
};

class FahrenheitSensor {
public:
    float getFahrenheitTemp() {
        float t = 32.0;
        return t;
    }
};

class Sensor {
public:
    virtual ~Sensor() {}
    virtual float getTemperature() = 0;
};

class Adapter : public Sensor {
public:
    Adapter(FahrenheitSensor *p) : pSensor(p) {}
    ~Adapter() {
        delete pSensor;
    }
    float getTemperature() {
        return (pSensor->getFahrenheitTemp() - 32.0) * 5.0 / 9.0;
    }
private:
    FahrenheitSensor *pSensor;
};

int main() {
    ModernComputer computer;
    PrinterAdapter adapter;

    computer.sendCommand("Print this in lowercase");
    adapter.sendCommand("Print this in lowercase(adapted)");

    Sensor *p = new Adapter(new FahrenheitSensor);
    std::cout << "Celcius temparature = " << p->getTemperature() << std::endl;

    return 0;
}