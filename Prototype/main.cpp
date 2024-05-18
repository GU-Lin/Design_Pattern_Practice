#include <iostream>
#include <string>
#include <map>

using namespace std;

// Prototype類別
class Prototype {
public:
    virtual Prototype* clone() = 0;
};

// Car類別
class Car : public Prototype {
private:
    string make;
    string model;
    string year;
    string color;

public:
    Car(string make, string model, string year, string color)
        : make(make), model(model), year(year), color(color) {}

    // Clone方法
    Prototype* clone() override {
        return new Car(*this);
    }

    void set_year(string in_year){
        this->year = in_year;
    }

    void set_make(string in_make){
        this->make = in_make;
    }

    void set_color(string in_color){
        this->color = in_color;
    }

    void set_model(string in_model){
        this->model = in_model;
    }

    void print() {
        cout << color << " " << year << " " << make << " " << model << endl;
    }
};

// PrototypeManager類別
class PrototypeManager {
private:
    map<string, Prototype*> prototypes;

public:
    void registerObject(string name, Prototype* obj) {
        prototypes[name] = obj;
    }

    Prototype* clone(string name) {
        if (prototypes.find(name) != prototypes.end()) {
            return prototypes.at(name)->clone();
        }
        return nullptr;
    }
};

int main() {
    PrototypeManager manager;

    // 創建Car對象
    Car* car = new Car("Toyota", "Camry", "2022", "Red");
    cout << car << endl;
    car->print();
    // 註冊Car對象
    manager.registerObject("car", car);

    // Clone the car
    Car* newCar = dynamic_cast<Car*>(manager.clone("car"));
    newCar->set_year("2024");
    newCar->set_make("Tesla");
    newCar->set_model("Y");
    newCar->set_color("White");

    if (newCar) {
        car->print();
        newCar->print();  // Output: Red 2022 Toyota Camry
        
        delete newCar;
    }

    return 0;
}

