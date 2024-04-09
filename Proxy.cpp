#include <iostream>

class Image {
public:
    virtual void display() = 0;
};

class RealImage : public Image {
private:
    std::string filename;
public:
    RealImage(const std::string &filename) : filename(filename) {
        std::cout << "Loading image: " << filename << std::endl;
    }
    void display() override {
        std::cout << "Displaying image: " << filename << std::endl;
    }
};

class ImageProxy : public Image {
private:
    RealImage *realImage;
    std::string filename;
public:
    ImageProxy(const std::string &filename) : filename(filename), realImage(nullptr) {}
    void display() override {
        if(realImage == nullptr) {
            realImage = new RealImage(filename);
        }
        realImage->display();
    }
};

int main() {
    Image *image = new ImageProxy("example.jpg");
    image->display();
    image->display();
    delete image;
    return 0;
}