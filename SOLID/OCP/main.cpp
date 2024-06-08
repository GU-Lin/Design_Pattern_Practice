#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<memory>
// Abstract base class
using namespace std;
template<typename T>
class Shape {
public:
    virtual double area()   const = 0;
    virtual double around() const = 0;
    string name ;
    // string name;
    virtual ~Shape() = default; // Ensure proper cleanup of derived classes
};

template<typename T>
class Rectangle : public Shape<T> {
private:
    double width, height;

public:
    // string name;
    Rectangle(double w, double h) : width(w), height(h) {
        this->name = "rectangle";
    }

    double area() const override {
        return width * height;
    }

    double around() const override {
        return 2*(width + height);
    }

    
};

template<typename T>
class Circle : public Shape<T> {
private:
    double radius;

public:
    // string name;
    Circle(double r) : radius(r) {
        this->name = "circle";
    }

    double area() const override {
        return M_PI * radius * radius; // Simple area calculation for demonstration
    }

    double around() const override {
        return 2*radius*M_PI;
    }
};

int main(){

    Circle<double> R1(10.0);
    Rectangle<double> M1(8.0,4.0);

    vector<Shape<double>*>table;
    table.push_back(&R1);
    table.push_back(&M1);
    for(int i = 0; i < table.size();i++){
        cout << "Area of " << table[i]->name << " : " << table[i]->area() << endl;
        cout << "Around of " << table[i]->name << " : " << table[i]->around() << endl;
    }
    return 0;

}