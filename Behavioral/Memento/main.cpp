#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct game_file{
    int chapter{0};
    string name{""};
    string location{""};
};
class Memento {
    public:
        game_file GetState(){
            return file;
        }
        game_file file;
};

class Originator{
    public:
        Originator(){}
        ~Originator(){}
        game_file GetState(){
            return file;
        }
        void SetState(game_file in_file){
            file = in_file;        
        }
        Memento* CreateMemento(){
            Memento* m_new = new Memento;
            m_new->file = file;
            return m_new;
        }
        void Restore(Memento* m){
            file = m->file;
        }
        void Display(){
            cout << "-----------------" << endl;
            cout << "Chapter  : " << file.chapter << endl;
            cout << "Player   : " << file.name << endl;
            cout << "Location : " << file.location << endl;
        }
    private:
        game_file file;
};
class CareTaker{
    public:
        vector<Memento*> memento_list;
        void add_memento(Memento* memento){
            memento_list.emplace_back(memento);
        };
        Memento* get_memento(int value){
            if(value>=0 && value < memento_list.size()){
                return memento_list[value];
            }else{
                return nullptr;
            }
        };
};
int main()
{
    // Set state and player
    Memento state;
    state.file.name = "Jack";
    state.file.location = "Sea-1";
    state.file.chapter = 0;
    Originator player;
    player.SetState(state.file);
    player.Display();

    // Set game recorder(CareTaker)
    CareTaker game_recorder;
    game_recorder.add_memento(player.CreateMemento());

    state.file.name = "Jack";
    state.file.location = "Sea-2";
    state.file.chapter = 1;
    player.SetState(state.file);
    player.Display();
    game_recorder.add_memento(player.CreateMemento());

    player.Restore(game_recorder.get_memento(0));
    player.Display();

    return 0;
}