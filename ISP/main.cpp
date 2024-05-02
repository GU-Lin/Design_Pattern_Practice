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

class game{
public:
    void virtual start(){}
};

class develop{
public:
    void virtual develop_mode(){}
};

class User : public game{
public:
    void start() override{
        cout << "Start game" << endl;
    }
};

class Coder : public game, develop{
public:
    void start() override{
        cout << "Coder start game" << endl;
    }
    void develop_mode() override{
        cout << "Develop mode on" << endl;
    }
};

int main(){

    User Jack;
    Coder Shawn;
    Jack.start();
    Shawn.start();
    Shawn.develop_mode();
    return 0;
}