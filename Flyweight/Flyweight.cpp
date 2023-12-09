#include <iostream>
#include <unordered_map>
#include <string>
#include <Windows.h>


class Flyweight {
public:
    virtual void operation() const = 0;
};


class ConcreteFlyweight : public Flyweight {
private:
    std::string intrinsicState;

public:
    ConcreteFlyweight(const std::string& intrinsicState) : intrinsicState(intrinsicState) {}

    void operation() const override {
        std::cout << "ConcreteFlyweight з інтризичним станом: " << intrinsicState << std::endl;
    }
};


class FlyweightFactory {
private:
    std::unordered_map<std::string, Flyweight*> flyweights;

public:
    Flyweight* getFlyweight(const std::string& key) {
        if (flyweights.find(key) == flyweights.end()) {
            flyweights[key] = new ConcreteFlyweight(key);
        }
        return flyweights[key];
    }

    ~FlyweightFactory() {
        for (const auto& pair : flyweights) {
            delete pair.second;
        }
        flyweights.clear();
    }
};


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    FlyweightFactory factory;
    Flyweight* flyweight1 = factory.getFlyweight("A");
    Flyweight* flyweight2 = factory.getFlyweight("B");

   
    flyweight1->operation();
    flyweight2->operation();

    return 0;
}
