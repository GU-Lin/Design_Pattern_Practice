#include <iostream>
#include <memory>

using namespace std;

struct content{
    content(){};
    content(string name, string picture, bool pass_port, bool package):name{name},
    picture{picture},pass_port{pass_port},package_get{package_get}{}
    ~content(){}
    string name;
    string picture;
    bool   pass_port;
    bool   package_get;
    bool   all_check;

};

class administration_staff{

    public:
        administration_staff(){};
        ~administration_staff(){};
        virtual void handle(content &person_content) = 0;
        virtual void set_next(shared_ptr<administration_staff> &staff) = 0;
    
};

// 機場櫃檯
class passport_counter : public administration_staff{

    void handle(content &person_content) override{
        if(person_content.name==""||person_content.picture==""||!person_content.pass_port){
            cout << "Failed to check at passport_counter" << endl;
        }else{
            cout << "Success to check at passport_counter" << endl;
            next_handler->handle(person_content);
        }
    }
    void set_next(shared_ptr<administration_staff> &staff) override{
        next_handler = staff;
    }
    private:
        shared_ptr<administration_staff> next_handler = nullptr;
    
};
// 海關
class guard : public administration_staff{

    void handle(content &person_content) override{
        if(!person_content.package_get){
            cout << "Failed to check at guard" << endl;
        }else{
            person_content.all_check = true;
            cout << "Success to check at guard" << endl;
            next_handler->handle(person_content);
        }
    }
    void set_next(shared_ptr<administration_staff> &staff) override{
        next_handler = staff;
    }
    private:
        shared_ptr<administration_staff> next_handler = nullptr;
     
};
// 空姐
class stewardess : public administration_staff{

    void handle(content &person_content) override{
        if(!person_content.all_check ){
            cout << "Failed to check at stewardess" << endl;
        }else{
            cout << "Have fun for your travel" << endl;
        }
    }
    void set_next(shared_ptr<administration_staff> &staff) override{
        
    }
    // private:
    //     shared_ptr<administration_staff> next_handler = nullptr;
     
};

int main() {

    content passenger;
    passenger.name = "Jack";
    passenger.all_check = false;
    passenger.package_get = true;
    passenger.pass_port = true;
    passenger.picture = "person.png";

    shared_ptr<administration_staff> airport_counter = make_shared<passport_counter>();
    shared_ptr<administration_staff> airport_guard = make_shared<guard>();
    shared_ptr<administration_staff> airport_stewardess = make_shared<stewardess>();
    airport_counter->set_next(airport_guard);
    airport_guard->set_next(airport_stewardess);

    airport_counter->handle(passenger);

    return 0;
}