#include<iostream>

using namespace std;


class Game_UI{

public:
    void virtual start(){
        cout << "Game start" <<endl;
    }

    void virtual develop_mode(){
        cout << "Develop mode on for debug" << endl;
    }
};

class User : public Game_UI{

public:
    void start() override{
        cout << "User start a game" << endl;
    }
    void develop_mode() override{
        cout << "You can't do this" << endl;
    }
};

class Coder: public Game_UI{

public:
    void start() override{
        cout << "Coder start a game" << endl;
    }
    void develop_mode() override{
        cout << "Coder turn on develop mode" << endl;
    }
};

int main(){

    User Jack;
    Coder Shawn;
    Jack.start();
    Jack.develop_mode();
    Shawn.start();
    Shawn.develop_mode();

    return 0;
}