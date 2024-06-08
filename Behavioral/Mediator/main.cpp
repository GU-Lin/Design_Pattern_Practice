#include <iostream>
#include <string>
#include <memory>
#include <list>

using namespace std;
class Collcogue;

class Mediator{
    public:
    list<Collcogue*> collcogue_list;
        Mediator(){};
        ~Mediator(){};
        virtual void brocast(Collcogue *person, string message)= 0;
        virtual void handle_personnal_message(Collcogue *src, Collcogue *dst,string message)= 0;
        virtual void ban(Collcogue *person)= 0;
        virtual void enter_room(Collcogue *person,string message)= 0;
};

class Collcogue{
    public:
        Mediator* room;
        string name="";
        Collcogue(){};
        ~Collcogue(){};
        virtual void send_message(string message) = 0; 
        virtual void send_personnal_message(Collcogue* person,string message) = 0;
        virtual void get_message(Collcogue *person,string message) = 0;
};

class player : public Collcogue{
    public:
        
        player(string in_name,Mediator *in_room){
            name = in_name;
            room = in_room;
            string message = name+" enter the chat room.";
            room->enter_room(this, message);
        }
        ~player(){
            cout << name << " bye bye" << endl;
        }
        void send_message(string message){
            if(room!=nullptr){
                room->brocast(this, message);
            }
        }
        void get_message(Collcogue *person,string message){
            cout << name << " get from room ->" << person->name << " : " << message << endl;
        }
        void send_personnal_message(Collcogue *person,string message){
            room->handle_personnal_message(this, person, message);
        }

};


class Room : public Mediator{
    void brocast(Collcogue *person, string message) override{
        for(auto p : collcogue_list){
                if(p != person){
                    if(message=="Loser"){
                        p->get_message(person, person->name + " will be banned");
                        ban(person);
                    }else{
                        p->get_message(person, message);
                    }
                    
                }
            }
    }
    void enter_room(Collcogue *person,string message) override{    
        for (auto p : collcogue_list) {
            if (p == person) {
                cout << person->name << " is already in the room." << endl;
                return; 
            }
        }
        collcogue_list.push_back(person);
        cout << message << endl;
    }
    void ban(Collcogue *person) override{
        for(auto p : collcogue_list){
            if(p==person){
                p->room=nullptr;
                collcogue_list.remove(p);
                cout << "Bye bye " << p->name << endl;
                break;
            }
        }
    }
    void handle_personnal_message(Collcogue *src, Collcogue *dst,string message) override{
        for(auto p : collcogue_list){
            if(message=="Loser"){
                if(p!=src){
                    p->get_message(src, src->name + " will be banned");
                }
            }else{
                if(p==dst){
                    dst->get_message(src,message);
                    break;
                }
            }
        }
        if(message=="Loser"){
            ban(src);
        }
    }
};

int main()
{

    Room* room = new Room();
    unique_ptr<Collcogue> Jack = make_unique<player>("Jack",room);
    unique_ptr<Collcogue> Shawn = make_unique<player>("Shawn",room);
    unique_ptr<Collcogue> Jun = make_unique<player>("Jun",room);

    Jack->send_message("Hello");
    Shawn->send_message("Choose your hero");
    Jun->send_personnal_message(Jack.get(),"Loser");
    Jun->send_message("???");
    return 0;
}
