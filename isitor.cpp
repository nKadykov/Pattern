#include <iostream>
#include <vector>

class Circle;
class Square;

class ShapeVisitor {
public:
    virtual void visit(Circle &circle) = 0;
    virtual void visit(Square &square) = 0;
};

class Shape {
public:
    virtual void accept(ShapeVisitor &visitor) = 0;
};

class Circle : public Shape {
public:
    void accept(ShapeVisitor &visitor) override {
        visitor.visit(*this);
    }
    void draw() {
        std::cout << "Drawing Circle\n";
    }
};

class Square : public Shape {
public:
    void accept(ShapeVisitor &visitor) override {
        visitor.visit(*this);
    }
    void draw() {
        std::cout << "Drawing Square\n";
    }
};

class DrawingVisitors : public ShapeVisitor {
public:
    void visit(Circle &circle) override {
        std::cout << "Drawing a Circle\n";
        circle.draw();
    }
    void visit(Square &square) override {
        std::cout << "Drawing a Square\n";
        square.draw();
    }
};

class AreaVisitor : public ShapeVisitor {
public:
    void visit(Circle &circle) override {
        std::cout << "Calculating area of Circle\n";
    }
    void visit(Square &square) override {
        std::cout << "Calculating area of Square\n";
    }
};

class ShapeContainer {
public:
    void addShape(Shape *shape) {
        shapes.push_back(shape);
    }
    void performOperations(ShapeVisitor &visitor) {
        for(Shape *shape : shapes) {
            shape->accept(visitor);
        }
    }
private:
    std::vector<Shape *> shapes;
};

int main() {
    Circle circle;
    Square square;

    ShapeContainer container;
    container.addShape(&circle);
    container.addShape(&square);

    DrawingVisitors drawingVisitor;
    AreaVisitor areaVisitor;

    container.performOperations(drawingVisitor);
    container.performOperations(areaVisitor);

    return 0;
}