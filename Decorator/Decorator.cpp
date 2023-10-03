#include <iostream>

// Component
class Coffee {
public:
    virtual double cost() = 0;
};

// ConcreteComponent
class SimpleCoffee : public Coffee {
public:
    double cost() override {
        return 5.0;
    }
};

// Decorator
class CoffeeDecorator : public Coffee {
protected:
    Coffee* decoratedCoffee;

public:
    CoffeeDecorator(Coffee* coffee) : decoratedCoffee(coffee) {}

    double cost() override {
        return decoratedCoffee->cost();
    }
};

// ConcreteDecorator
class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(Coffee* coffee) : CoffeeDecorator(coffee) {}

    double cost() override {
        return CoffeeDecorator::cost() + 2.0;
    }
};

// ConcreteDecorator
class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(Coffee* coffee) : CoffeeDecorator(coffee) {}

    double cost() override {
        return CoffeeDecorator::cost() + 1.0;
    }
};

int main() {
    Coffee* coffee = new SimpleCoffee();
    std::cout << "Cost of plain coffee: " << coffee->cost() << std::endl;

    Coffee* milkCoffee = new MilkDecorator(coffee);
    std::cout << "Cost of coffee with milk: " << milkCoffee->cost() << std::endl;

    Coffee* sugarMilkCoffee = new SugarDecorator(milkCoffee);
    std::cout << "Cost of coffee with milk and sugar: " << sugarMilkCoffee->cost() << std::endl;

    delete sugarMilkCoffee;
    delete milkCoffee;
    delete coffee;

    return 0;
}
