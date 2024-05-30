#include <iostream>
#include <memory>

using namespace std;

class meal{

    public:
        void operation(){
            make_soup();
            make_meat();
            make_comes_with_meal();
            
        }

        virtual void make_soup() = 0;
        virtual void make_meat() = 0;
        virtual void make_comes_with_meal() = 0;


};

class steak : public meal{
    void make_soup() override {
        cout << "Make corn soup" << endl;
    }
    void make_meat() override {
        cout << "Make steak" << endl;
    }
    void make_comes_with_meal() override {
        cout << "Make noodles" << endl;
    }
};

class pork_chops : public meal{
    void make_soup() override {
        cout << "Make miso soup" << endl;
    }
    void make_meat() override {
        cout << "Make pork chops" << endl;
    }
    void make_comes_with_meal() override {
        cout << "Make rice" << endl;
    }
};

int main(){
    cout << "----------------" << endl;
    steak steak_meal;
    steak_meal.operation();
    cout << "----------------" << endl;
    pork_chops pork_chops_meal;
    pork_chops_meal.operation();
    cout << "----------------" << endl;
}