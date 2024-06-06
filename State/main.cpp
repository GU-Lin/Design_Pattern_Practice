#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;
int count_num = 0;

class Rumble;
class State{
    public:
        virtual void handle(Rumble* hero) = 0;
};


class Normal_State : public State{
    public:
        void handle(Rumble* hero) override;
};

class Warning_State : public State{
    public:
        void handle(Rumble* hero) override;
};

class OverHeat_State : public State{
    public:
        void handle(Rumble* hero) override;
};

class Rumble{
    public:
        unique_ptr<State> hero_state=nullptr;
        // State* hero_state;
        Rumble(){
            hero_state = make_unique<Normal_State>();
        }
        ~Rumble(){};
        void run(){
            
            while(1){
                if(count_num>=3)break;
                hero_state->handle(this);
            }
            
        }
};

void Normal_State::handle(Rumble* hero) {
    hero->hero_state = make_unique<Warning_State>();
    cout << "-------------------" << endl;
    cout << "Normal State" << endl;
    cout << "Attack is 50" << endl;
}

void Warning_State::handle(class Rumble* hero){
    hero->hero_state = make_unique<OverHeat_State>();
    cout << "-------------------" << endl;
    cout << "Warning State" << endl;
    cout << "Attack is 75" << endl;
}

void OverHeat_State::handle(class Rumble* hero){
    hero->hero_state = make_unique<Normal_State>();
    count_num++;
    cout << "-------------------" << endl;
    cout << "Over Heat State" << endl;
    cout << "Can't control Rumble" << endl;
    cout << "Attack is 100" << endl;
    cout << "Over Heat times " << count_num << endl;;
    
}

int main()
{
    Rumble hero;
    hero.run();

    return 0;
}