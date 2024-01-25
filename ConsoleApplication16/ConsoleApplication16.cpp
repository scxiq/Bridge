#include <iostream>

// Оголошення класу Implementation
class Implementation {
public:
    virtual void doOperation() const = 0;
};

// Абстракція
class Abstraction {
public:
    virtual void operation() const = 0;
};

// Конкретна абстракція
class ConcreteAbstraction : public Abstraction {
public:
    ConcreteAbstraction() : implementation_(nullptr) {}

    // Встановлення реалізації через конструктор або метод
    void setImplementation(Implementation* implementation) {
        implementation_ = implementation;
    }

    void operation() const override {
        if (implementation_)
            implementation_->doOperation();
    }

private:
    Implementation* implementation_;
};

// Реалізація
class ConcreteImplementationA : public Implementation {
public:
    void doOperation() const override {
        std::cout << "Concrete Implementation A\n";
    }
};

class ConcreteImplementationB : public Implementation {
public:
    void doOperation() const override {
        std::cout << "Concrete Implementation B\n";
    }
};

int main() {
    // Використання паттерна "Міст"
    ConcreteAbstraction abstraction;

    // Встановлення реалізації A
    abstraction.setImplementation(new ConcreteImplementationA());
    abstraction.operation();

    // Встановлення реалізації B
    abstraction.setImplementation(new ConcreteImplementationB());
    abstraction.operation();

    return 0;
}
