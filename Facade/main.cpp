#include<iostream>
using namespace std;

class machine{
    public:
        virtual void turn_on()=0;
        virtual void turn_off()=0;
};

class air_conditioner : public machine{
    public:
        void turn_on(){
            cout << "Turn on the air conditioner" << endl;
        }
        void turn_off(){
            cout << "Turn off the air conditioner" << endl;
        }
};

class TV : public machine{
    public:
        void turn_on(){
            cout << "Turn on the TV" << endl;
        }
        void turn_off(){
            cout << "Turn off the TV" << endl;
        }
};

class controler{
    public:
        void turn_on(){
            tv.turn_on();
            ac.turn_on();
        }
        void turn_off(){
            tv.turn_off();
            ac.turn_off();
        }
    private:
        TV tv;
        air_conditioner ac;
};

int main(){

    controler ct;
    ct.turn_on();
    ct.turn_off();
    return 0;
}