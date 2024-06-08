#include<iostream>
#include<memory>
using namespace std;

enum MEAT_CODE{
    MEAT_PORK = 0,
    MEAT_BEEF
};

class meat{
    public:
        meat(){};
        ~meat(){};
        void virtual make() = 0;
        void virtual info() = 0;
};

class pork : public  meat{
    public:
        void make() override{
            cout << "A pound of pork is made." << endl;
        }
        void info() override{
            cout << "It is pork." << endl;
        }
};

class beef : public  meat{
    public:
        void make() override{
            cout << "A pound of beef is made." << endl;
        }
        void info() override{
            cout << "It is beef." << endl;
        }
};

class Meat_Factory{
    public:
        Meat_Factory(){};
        ~Meat_Factory(){};
        std::shared_ptr<meat> make(MEAT_CODE type){
            if(type==MEAT_PORK){
                Meat = std::make_shared<pork>();
            }else{
                Meat = std::make_shared<beef>();
            }
            Meat->make();
            return Meat;
        }
    private:
        std::shared_ptr<meat> Meat = nullptr;
};

class Factory{
    public:
        Factory(){};
        virtual ~Factory(){}
        virtual std::shared_ptr<meat> make() = 0;
};

class Pork_Factory : public Factory{
    public:
        std::shared_ptr<meat> make() override{
            product = std::make_shared<pork>();
            product->make();
            return product;
        }
    private:
        std::shared_ptr<meat> product = nullptr;
};

class Beef_Factory : public Factory{
    public:
        std::shared_ptr<meat> make() override{
            product = std::make_shared<beef>();
            product->make();
            return product;
        }
    private:
        std::shared_ptr<meat> product = nullptr;
};



int main(){
    // Meat_Factory meat_factory;
    // meat_factory.make(MEAT_BEEF)->info();

    Beef_Factory beef_factory;
    std::shared_ptr<meat> product = beef_factory.make();
    product->info();
    return 0;
}