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
        string name;
};

class pork : public  meat{
    public:
        void make() override{
            cout << "A pound of pork is made." << endl;
            name = "pork";
        }
        void info() override{
            cout << "It is " << name << endl;
        }
};

class beef : public  meat{
    public:
        void make() override{
            cout << "A pound of beef is made." << endl;
            name = "beef";
        }
        void info() override{
            cout << "It is " << name << endl;
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


class shape{
    public:
        shape(){};
        ~shape(){};
        string info;
        void virtual make() = 0;
};

class stripe : public shape{
    public:
        void make() override{
            cout << "Cut into stripe" << endl;
            info = "stripe";
        }
};

class cube : public shape{
    public:
        void make() override{
            cout << "Cut into cube" << endl;
            info = "cube";
        }
};


class Shape_Factory{
    public:
        Shape_Factory(){};
        virtual ~Shape_Factory(){}
        virtual std::shared_ptr<shape> make() = 0;
};

class Stripe_Factory : public Shape_Factory{
    public:
        std::shared_ptr<shape> make() override{
            product = std::make_shared<stripe>();
            product->make();
            return product;
        }
    private:
        std::shared_ptr<shape> product = nullptr;
};

class Cube_Factory : public Shape_Factory{
    public:
        std::shared_ptr<shape> make() override{
            product = std::make_shared<cube>();
            product->make();
            return product;
        }
    private:
        std::shared_ptr<shape> product = nullptr;
};

class Abstract_Factory{
    public:
        virtual void make_meat() = 0;
        virtual void make_shape() = 0;
        std::shared_ptr<meat> meat_product;
        std::shared_ptr<shape>shape_product;
};

class Cube_Beef_Factory : public Abstract_Factory{
    public:
        void make_meat(){
            meat_product = std::make_shared<beef>();
            meat_product->make();
        }
        void make_shape(){
            shape_product = std::make_shared<cube>();
            shape_product->make();
        }
};


int main(){

    Cube_Beef_Factory cube_beef;
    cube_beef.make_meat();
    cube_beef.make_shape();
    cout << cube_beef.meat_product->name << endl;
    cout << cube_beef.shape_product->info << endl;
    return 0;
}