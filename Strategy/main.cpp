# include<iostream>
# include<memory>
using namespace std;

class action{
    public:
        action(){};
        virtual void go()=0;
        virtual ~action(){};
};

class ride : public action{
    public:
        void go() override{
            cout <<  " is riding!" << endl;
        }
};

class drive : public action{
    public:
        void go() override{
            cout <<  " is driving!" << endl;
        }
};

class run : public action{
    public:
        void go() override{
            cout << " is running!" << endl;
        }
};
class User{
    public:
        string name;
        User(string user){
            name = user;
        }
        ~User(){};
        void choose(std::shared_ptr<action>&act){
            action_to_do = act;
        }
        void go(){
            cout << name;
            action_to_do->go();
        }
    private:
        std::shared_ptr<action>action_to_do=nullptr;
};

int main(){
    std::shared_ptr<User> Jack = std::make_shared<User>("Jack");
    std::shared_ptr<action> strategy= std::make_shared<drive>();
    Jack->choose(strategy);
    Jack->go();
    return 0;
}
