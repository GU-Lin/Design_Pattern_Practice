#include<iostream>
#include<string>
#include<vector>
using namespace std;

// Before
struct waiter1{
    string name = "";
    waiter1(const string &name):name(name){}

    vector<string> item_to_order; 
    void order(string item){
        cout << "Order : " << item << endl;
        item_to_order.push_back(item);
    } 

    void notify_chief(string item){
        if(item.size()==0) return;
        for(int i = 0; i < item.size(); i++){
            item.pop_back();
        }
        cout << "Chief got the order." << endl;
    }

    void check_bill(){
        cout << name << " is checking bill." << endl;
    }

    void handle_calling(){
        cout << name << " is handling calling." << endl;
    }

};

// After
struct waiter2{
    string name = "";
    waiter2(const string &name):name(name){}

    vector<string> item_to_order; 
    void order(string item){
        cout << "Order : " << item << endl;
        item_to_order.push_back(item);
    } 

    void notify_chief(){
        if(item_to_order.size()==0) return;
        int n = item_to_order.size();
        for(int i = 0; i < n; i++){
            item_to_order.pop_back();
        }
        cout << "Chief got the order.";
    }

};

struct counter{
    string name = "";
    counter(const string &name):name(name){}

    void check_bill(){
        cout << name << " is checking bill." << endl;
    }

    void handle_calling(){
        cout << name << " is handling calling." << endl;
    }

};



int main(){

    cout << "Hello World" << endl;
    counter Sam("Sam");
    waiter2 Jack("Jack");
    Jack.order("Beef");
    Jack.order("Pork");
    Jack.notify_chief();
    Sam.check_bill();
    Sam.handle_calling();

    return 0;
}