#include <iostream>
#include <vector>

class Product1 {
public:
    std::vector<std::string> m_parts;
    void ListParts() const {
        std::cout << "Product parts: ";
        for(size_t i = 0; i < m_parts.size(); ++i) {
            if(m_parts[i] == m_parts.back()) {
                std::cout << m_parts[i];
            }
            else {
                std::cout << m_parts[i] << ", ";
            }
        }
        std::cout << "\n\n";
    }
};

class Builder {
public:
    virtual ~Builder() {}
    virtual void ProducePartA() const = 0;
    virtual void ProducePartB() const = 0;
    virtual void ProducePartC() const = 0;
};

class ConcreteBuilder1 : public Builder {
public:
    ConcreteBuilder1() {
        this->Reset();
    }
    ~ConcreteBuilder1() {
        delete m_product;
    }
    void Reset() {
        this->m_product = new Product1();
    }
    void ProducePartA() const override {
        this->m_product->m_parts.push_back("PartA1");
    }
    void ProducePartB() const override {
        this->m_product->m_parts.push_back("PartB1");
    }
    void ProducePartC() const override {
        this->m_product->m_parts.push_back("PartC1");
    }
    Product1* GetProduct() {
        Product1* result = this->m_product;
        this->Reset();
        return result;
    }
private:
    Product1* m_product;
};

class Director {
public:
    void setBuilder(Builder* builder) {
        this->m_builder = builder;
    }
    void BuildMinimalViableProduct() {
        this->m_builder->ProducePartA();
    }
    void BuildFullFeaturedProduct() {
        this->m_builder->ProducePartA();
        this->m_builder->ProducePartB();
        this->m_builder->ProducePartC();
    }
private:
    Builder* m_builder;
};

void ClientCode(Director& director) {
    ConcreteBuilder1* builder = new ConcreteBuilder1();
    director.setBuilder(builder);
    std::cout << "Standart basic product:\n";
    director.BuildMinimalViableProduct();

    Product1* p = builder->GetProduct();
    p->ListParts();
    delete p;

    std::cout << "Standart full featured product:\n";
    director.BuildFullFeaturedProduct();

    p = builder->GetProduct();
    p->ListParts();
    delete p;

    std::cout << "Custom product:\n";
    builder->ProducePartA();
    builder->ProducePartC();
    p = builder->GetProduct();
    p->ListParts();
    delete p;

    delete builder;
}

int main() {
    Director* director = new Director();
    ClientCode(*director);
    delete director;
    return 0;
}