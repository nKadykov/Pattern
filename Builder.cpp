#include <iostream>
#include <string>

class Computer {
public:
    void setCPU(const std::string &c) {
        cpu = c;
    }
    void setMemory(const std::string &m) {
        memory = m;
    }
    void setStorage(const std::string &s) {
        storage = s;
    }
    void display() {
        std::cout << "CPU: " << cpu << std::endl;
        std::cout << "Memory: " << memory << std::endl;
        std::cout << "Storage: " << storage << std::endl;
    }
private:
    std::string cpu;
    std::string memory;
    std::string storage;
};

class ComputerBuilder {
public:
    virtual void buildCPU(const std::string &cpy) = 0;
    virtual void buildMemory(const std::string &memory) = 0;
    virtual void buildStorage(const std::string &storage) = 0;
    virtual Computer getResult() = 0;
};

class DesktopComputerBuilder : public ComputerBuilder {
public:
    DesktopComputerBuilder() {
        computer = Computer();
    }
    void buildCPU(const std::string &cpu) override {
        computer.setCPU(cpu);
    }
    void buildMemory(const std::string &memory) override {
        computer.setMemory(memory);
    }
    void buildStorage(const std::string &storage) override {
        computer.setStorage(storage);
    }
    Computer getResult() override {
        return computer;
    }
private:
    Computer computer;
};

class ComputerAssembler {
public:
    Computer assembleComputer(ComputerBuilder &builder) {
        builder.buildCPU("Inter i7");
        builder.buildMemory("16GB");
        builder.buildStorage("512GB SSD");
        return builder.getResult();
    }
};

int main() {
    DesktopComputerBuilder desktopBuilder;
    ComputerAssembler assembler;
    Computer desktop = assembler.assembleComputer(desktopBuilder);

    std::cout << "Desktop Computer Configuration: " << std::endl;
    desktop.display();

    return 0;
}