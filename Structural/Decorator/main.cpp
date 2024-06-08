#include <iostream>
#include <string>
#include <memory>
using namespace std;

// 1. Component Interface
class tea{
    public:
        virtual string get_info() const = 0;
        virtual int cost() const = 0;
};

// 2. Concrete Component

class milk_tea : public tea{
    public:
        string get_info() const override{
            return "A cup of milk ";
        }
        int cost() const override{
            return 50;
        }
};

// 3. Decorator

class tea_materials_Decorator : public tea{
    public:
        std::shared_ptr<tea> m_tea;
        tea_materials_Decorator( std::shared_ptr<tea> &in_put):m_tea(in_put){};
        ~tea_materials_Decorator(){};
        string get_info() const override{
            return m_tea->get_info();
        }
        int cost() const override{
            return m_tea->cost();
        }
};

// 4. Concrete Decorator
class bubble_Decorator : public tea_materials_Decorator{
    public:
    bubble_Decorator(std::shared_ptr<tea> &in_put):tea_materials_Decorator(in_put){};
    ~bubble_Decorator(){}
    string get_info() const {
            return m_tea->get_info()+", add bubble";
    }
    int cost() const {
            return m_tea->cost() + 5;
    }
};

class pudding_Decorator : public tea_materials_Decorator{
    public:
    pudding_Decorator(std::shared_ptr<tea> &in_put):tea_materials_Decorator(in_put){};
    ~pudding_Decorator(){}
    string get_info() const {
            return m_tea->get_info()+", add pudding";
    }
    int cost() const {
            return m_tea->cost() + 10;
    }
};


int main(){

    std::shared_ptr<tea> product_milk_tea = std::make_shared<milk_tea>();
    std::shared_ptr<tea> bubble_milk_tea = std::make_shared<bubble_Decorator>(product_milk_tea);
    std::shared_ptr<tea> pudding_bubble_milk_tea = std::make_shared<pudding_Decorator>(bubble_milk_tea);

    cout << bubble_milk_tea->get_info() << endl;
    cout << bubble_milk_tea->cost() << endl;
    cout << pudding_bubble_milk_tea->get_info() << endl;
    cout << pudding_bubble_milk_tea->cost() << endl;

    return 0;
}