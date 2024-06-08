#include<iostream>
#include<string>
using namespace std;
// Product class
class Iphone{
    public:
        string name;
        string color;
        string cpu;
        float screen_size;
        int resoltion_w;
        int resoltion_h;
        void info(){
            cout << "Type            : " << name << endl;
            cout << "CPU             : " << cpu << endl;
            cout << "Color           : " << color << endl;
            cout << "Screen_size     : " << screen_size << endl;
            cout << "resoltion_w     : " << resoltion_w << endl;
            cout << "resoltion_h     : " << resoltion_h << endl;
        }
};
// Abstract builder class
class Iphone_Builder {
public:
    virtual void set_name(string name) = 0;
    virtual void set_color(string name) = 0;
    virtual void set_cpu(string cpu) = 0;
    virtual void set_screen_size(float screen_size) = 0;
    virtual void set_resoltion_w(int w) = 0;
    virtual void set_resoltion_h(int h) = 0;
    virtual Iphone get_iphone() const  = 0;

};
// Concrete builder for a specific type of drink
class Iphone_Builder_Concrete : public Iphone_Builder{
    public:
        void set_name(string name) override{
            iphone.name = name;
        }
        
        void set_color(string color) override{
            iphone.color = color;
        }
        void set_cpu(string cpu)override{
            iphone.cpu = cpu;
        }
        void set_screen_size(float screen_size)override{
            iphone.screen_size = screen_size;
        }
        void set_resoltion_w(int w) override{
            iphone.resoltion_w = w;
        }
        void set_resoltion_h(int h) override{
            iphone.resoltion_h = h;
        }
        Iphone get_iphone()const override{
            return iphone;
        }

    private:
        Iphone iphone;
};
 
// Director class that orchestrates the construction
class Apple{
    public:
        Iphone make_I15(Iphone_Builder_Concrete& builder_concrete){
            builder_concrete.set_name("I15");
            builder_concrete.set_cpu("A16");
            builder_concrete.set_screen_size(6.1);
            builder_concrete.set_color("White");
            builder_concrete.set_resoltion_h(2556);
            builder_concrete.set_resoltion_w(1179);
            return builder_concrete.get_iphone();
        }
        Iphone make_I15_pro(Iphone_Builder_Concrete& builder_concrete){
            builder_concrete.set_name("I15 pro");
            builder_concrete.set_cpu("A17");
            builder_concrete.set_screen_size(6.1);
            builder_concrete.set_color("White");
            builder_concrete.set_resoltion_h(2556);
            builder_concrete.set_resoltion_w(1179);
            return builder_concrete.get_iphone();
        }
        Iphone make_I15_plus(Iphone_Builder_Concrete& builder_concrete){
            builder_concrete.set_name("I15_plus");
            builder_concrete.set_cpu("A16");
            builder_concrete.set_screen_size(6.7);
            builder_concrete.set_color("White");
            builder_concrete.set_resoltion_h(2796);
            builder_concrete.set_resoltion_w(1290);
            return builder_concrete.get_iphone();
        }
    
};
 

int main()
{
    Iphone_Builder_Concrete builder_concrete;
    Apple apple;
    Iphone iphone = apple.make_I15_plus(builder_concrete);
    iphone.info();
    return 0;
}