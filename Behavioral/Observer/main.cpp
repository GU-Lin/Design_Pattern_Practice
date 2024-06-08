#include<iostream>
#include<memory>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

class Scriber{
    public:
        virtual void update(string program) = 0;
};

class ConcreteScriber : public Scriber{
    public:
        string m_name;
        ConcreteScriber(string name):m_name(name){};
        ~ConcreteScriber(){};
        void update(string program) override{
            cout << "Hi " << m_name << ", new video " << program << " is update." << endl;
        }
};

class Youtube{
    public:
        Youtube(){};
        ~Youtube(){};
        virtual void attach(std::shared_ptr<Scriber> pObserver) = 0;
        virtual void detach(std::shared_ptr<Scriber> pObserver) = 0;
        virtual void notify(string program) = 0;
        set<std::shared_ptr<Scriber>> m_ObserverList;
};

class YoutubeChannel : public Youtube{
    public:

        YoutubeChannel(){};
        ~YoutubeChannel(){};
        void attach(std::shared_ptr<Scriber> pObserver) override{
            auto iter = std::find(m_ObserverList.begin(), m_ObserverList.end(), pObserver);
            if(iter==m_ObserverList.end()){
                m_ObserverList.insert(pObserver);
            }
        }
        void detach(std::shared_ptr<Scriber> pObserver) override{          
            m_ObserverList.erase(pObserver);
        }
        void notify(string program) override{
            for(auto iter: m_ObserverList){
                iter->update(program);
            }
        }
};

int main() {

    YoutubeChannel AnnoyOrange;

    shared_ptr<ConcreteScriber> Jack = make_shared<ConcreteScriber>("Jack");
    shared_ptr<ConcreteScriber> Sam  = make_shared<ConcreteScriber>("Sam");
    shared_ptr<ConcreteScriber> Amy  = make_shared<ConcreteScriber>("Amy");
    AnnoyOrange.attach(Jack);
    AnnoyOrange.attach(Sam);
    AnnoyOrange.attach(Amy);
    AnnoyOrange.notify("Annoying orange ep1");
    cout << "----------------------------" << endl;
    AnnoyOrange.detach(Sam);
    AnnoyOrange.notify("Annoying orange ep2");
    return 0;
}