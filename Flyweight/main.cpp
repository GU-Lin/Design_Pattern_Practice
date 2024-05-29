#include <iostream>
#include <unordered_map>

class Flyweight {
public:
    virtual void operation() = 0;
};

class ConcreteFlyweight : public Flyweight {
private:
    int intrinsicState; // 內在狀態

public:
    ConcreteFlyweight(int state) : intrinsicState(state) {}

    void operation() override {
        std::cout << "ConcreteFlyweight: Intrinsic State is " << intrinsicState << std::endl;
        std::cout << &intrinsicState << std::endl;
    }
};

class FlyweightFactory {
private:
    std::unordered_map<int, Flyweight*> flyweights;

public:
    Flyweight* getFlyweight(int key) {
        if (flyweights.find(key) == flyweights.end()) {
            flyweights[key] = new ConcreteFlyweight(key);
        }
        return flyweights[key];
    }

    ~FlyweightFactory() {
        for (auto& pair : flyweights) {
            delete pair.second;
        }
    }
};

int main() {
    FlyweightFactory factory;

    Flyweight* flyweight1 = factory.getFlyweight(1);
    flyweight1->operation();

    Flyweight* flyweight2 = factory.getFlyweight(2);
    flyweight2->operation();

    Flyweight* flyweight3 = factory.getFlyweight(1); // 重複使用相同的享元
    flyweight3->operation();

    // 清理
    delete flyweight1;
    delete flyweight2;
    delete flyweight3;

    return 0;
}