#include <iostream>
#include <string>
#include <memory>

using namespace std;
class video{
    public:
        virtual void show() const = 0;
};

class channel : public video{
    public:
        string channel_name ;
        channel(string name):channel_name(name){};
        void show() const override{
            cout << "Channel name: " << channel_name << endl;
        }
        ~channel(){};
};

class TV_box : public video{
    public:
        TV_box(string name){
            m_channel = make_shared<channel>(name);
        }
        void show() const override{
            m_channel->show();
            cout << "Have fun!" << endl;
        }
        ~TV_box(){};
    private:
        shared_ptr<channel> m_channel;
};

int main(){
    shared_ptr<TV_box> box = make_shared<TV_box>("Cartoon network");
    box->show();

    return 0;
}