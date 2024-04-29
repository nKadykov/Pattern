#include <iostream>

class Shape {
public:
    virtual void draw() = 0;
};

class Renderer {
public:
    virtual void render() = 0;
};

class VectorRenderer : public Renderer {
public:
    void render() override {
        std::cout << "Rendering as a vector\n";
    }
};

class RasterRenderer : public Renderer {
public:
    void render() override {
        std::cout << "Rendering as a raster\n";
    }
};

class Circle : public Shape {
public:
    Circle(Renderer &renderer) : renderer(renderer) {}
    void draw() override {
        std::cout << "Drawing a circle ";
        renderer.render();
    }
private:
    Renderer &renderer;
};

class Square : public Shape {
public:
    Square(Renderer &renderer) : renderer(renderer) {}
    void draw() override {
        std::cout << "Drawing a square ";
        renderer.render();
    }
private:
    Renderer &renderer;
};

int main() {
    VectorRenderer vectorRenderer;
    RasterRenderer rasterRenderer;

    Circle circle(vectorRenderer);
    Square square(rasterRenderer);

    circle.draw();
    square.draw();

    Circle circle2(rasterRenderer);
    Square square2(vectorRenderer);

    circle2.draw();
    square2.draw();

    return 0;
}