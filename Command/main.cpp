#include<iostream>
#include<memory>
#include<queue>

using namespace std;

class command{
    public:
        command(){};
        ~command(){};
        virtual void execute() = 0;
};

// Reciver
class TV{
    public:
        void turn_on(){
            cout << "Turn on TV" << endl;
        }
        void turn_off(){
            cout << "Turn off TV" << endl;
        }
};

class air_conditioner{
    public:
        void turn_on(){
            cout << "Turn on air conditioner" <<endl;
        }

        void turn_sleep_well(){
            cout << "Sleep mode on" << endl;
        }

        void turn_filter(){
            cout << "Filter mode on" << endl;
        }

        void turn_off(){
            cout << "Turn off air conditioner" <<endl;
        }
};

class turn_on_command : public command{
    public:
        shared_ptr<TV> m_device;
        turn_on_command(shared_ptr<TV> device){
            m_device = device;
        }
        ~turn_on_command(){};
        void execute() override{
            m_device->turn_on();
        }
};

class turn_off_command : public command{
    public:
        shared_ptr<TV> m_device;
        turn_off_command(shared_ptr<TV> device){
            m_device = device;
        }
        ~turn_off_command(){};
        void execute() override{
            m_device->turn_off();
        }
};



class turn_on_ac_command : public command{
    public:
            shared_ptr<air_conditioner> m_device;
            turn_on_ac_command(shared_ptr<air_conditioner> device){
                m_device = device;
            }
            ~turn_on_ac_command(){};
            void execute() override{
                m_device->turn_on();
            }
};

class turn_off_ac_command : public command{
    public:
            shared_ptr<air_conditioner> m_device;
            turn_off_ac_command(shared_ptr<air_conditioner> device){
                m_device = device;
            }
            ~turn_off_ac_command(){};
            void execute() override{
                m_device->turn_off();
            }
};


class turn_filter_ac_command : public command{
    public:
            shared_ptr<air_conditioner> m_device;
            turn_filter_ac_command(shared_ptr<air_conditioner> device){
                m_device = device;
            }
            ~turn_filter_ac_command(){};
            void execute() override{
                m_device->turn_filter();
            }
};


class turn_sleep_well : public command{
    public:
            shared_ptr<air_conditioner> m_device;
            turn_sleep_well(shared_ptr<air_conditioner> device){
                m_device = device;
            }
            ~turn_sleep_well(){};
            void execute() override{
                m_device->turn_sleep_well();
            }
};

class control{
    private:
        queue<shared_ptr<command>> q_command;

    public:
        control(){};
        ~control(){};
        void add_command(shared_ptr<command> command){
            q_command.push(command);
        }


        void execute_single_command(){
            if(q_command.size()==0){
                cout << "No command" << endl;
            }
            else{
                q_command.front()->execute();
                q_command.pop();
            }
        }

        void execute_all_command(){
            if(q_command.size()==0){
                cout << "No command" << endl;
            }
            else{
                while(q_command.size()>0){
                    q_command.front()->execute();
                    q_command.pop();
                }
            }
            
        }
};

int main() {

    shared_ptr<TV> TV_52_inch = make_shared<TV>();
    shared_ptr<command> turn_on = make_shared<turn_on_command>(TV_52_inch);
    shared_ptr<command> turn_off = make_shared<turn_off_command>(TV_52_inch);

    shared_ptr<air_conditioner> window_type_ac = make_shared<air_conditioner>();
    shared_ptr<command> turn_on_ac = make_shared<turn_on_ac_command>(window_type_ac);
    shared_ptr<command> turn_off_ac = make_shared<turn_off_ac_command>(window_type_ac);
    shared_ptr<command> turn_on_filter = make_shared<turn_filter_ac_command>(window_type_ac);
    shared_ptr<command> turn_on_sleep_ewll = make_shared<turn_sleep_well>(window_type_ac);

    control controler;
    controler.add_command(turn_on);
    controler.execute_single_command();

    controler.add_command(turn_off);
    controler.execute_single_command();

    controler.add_command(turn_on_ac);
    controler.add_command(turn_on_filter);
    controler.add_command(turn_on_sleep_ewll);
    controler.add_command(turn_off_ac);

    controler.execute_all_command();
    return 0;
}