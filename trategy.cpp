#include <iostream>
#include <vector>

class SortingStrategy {
public:
    virtual void sort(std::vector<int> &arr) = 0;
};

class BubbleSort : public SortingStrategy {
public:
    void sort(std::vector<int> &arr) override {}
};

class QuickSort : public SortingStrategy {
public:
    void sort(std::vector<int> &arr) override {}
};

class SortContext {
private:
    SortingStrategy *strategy;
public:
    void setStrategy(SortingStrategy *strategy) {
        this->strategy = strategy;
    }
    void executeStrategy(std::vector<int> &arr) {
        strategy->sort(arr);
    }
};

int main() {
    std::vector<int> data = {5, 2, 7, 1, 9};

    SortContext context;
    BubbleSort bubbleSort;
    QuickSort quickSort;

    context.setStrategy(&bubbleSort);
    context.executeStrategy(data);

    context.setStrategy(&quickSort);
    context.executeStrategy(data);
    
    return 0;
}