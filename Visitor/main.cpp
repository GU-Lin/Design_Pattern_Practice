#include <iostream>
#include <vector>
using namespace std;
// Forward declaration of Visitor class
class Visitor;

// Element base class
class Element {
public:
    virtual void accept(Visitor &visitor) = 0;
};

// Concrete element classes
class Teacher : public Element {
public:
    string name;
    Teacher(string name):name(name){}
    ~Teacher(){}
    void accept(Visitor &visitor) override;
    void operation() {
        cout << name << " : Let's go to restaurant." << endl;
    }
};

class Guard : public Element {
public:
    string name;
    Guard(string name):name(name){}
    ~Guard(){}
    void accept(Visitor &visitor) override;
    void operation() {
        cout << name << " : OK, you can go to see your teacher." << endl;
    }
};

// Visitor base class
class Visitor {
public:
    virtual void visit(Teacher &element) = 0;
    virtual void visit(Guard &element) = 0;
};

// Concrete visitor class
class ConcreteVisitor : public Visitor {
public:
    void visit(Teacher &element) override {
        element.operation();
    }

    void visit(Guard &element) override {
        element.operation();
    }
};

// Implement accept method for ConcreteElementA
void Teacher::accept(Visitor &visitor) {
    visitor.visit(*this);
}

// Implement accept method for ConcreteElementB
void Guard::accept(Visitor &visitor) {
    visitor.visit(*this);
}

int main() {
    // Create elements
    Teacher Amy("Amy");
    Guard Shawn("Shawn");

    // Create visitor
    ConcreteVisitor visitor;

    // Call accept method for each element
    Shawn.accept(visitor);
    Amy.accept(visitor);

    return 0;
}
