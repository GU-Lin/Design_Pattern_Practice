#include<iostream>

using namespace std;

class Bird{
    public:
        virtual void eat(){
            cout << "Bird can eat" << endl;
        }
        virtual void jump(){
            cout << "Bird jump "  << endl;
        }
        
};

class Fly_bird : public Bird{
    public:
        virtual void fly() const{
            cout << "Fly bird flying "  << endl;
        }
};

class Swim_bird : public Bird{
    public:
        virtual void swim(){
            cout << "Swim bird is swimming" << endl;
        }
};

class Eagle : public Fly_bird{
    public:

        void fly(double distance) const  { 
            cout << "Eagle fly " << distance   << endl;
        }
        void jump() override{
            cout << "Eagle jump " << endl;
        }
};

class Pengium : public Swim_bird{
    public:
        void swim() override{
            cout << "Pengium can swim" << endl;
        }
        void jump() override{
            cout << "Pengium jump " << endl;
        }
};

int main(){

    Eagle eagle;
    Pengium pengium;
    eagle.fly(7.5);
    // eagle.fly();
    eagle.jump();
    pengium.swim();
    pengium.jump();
    
    return 0;
}