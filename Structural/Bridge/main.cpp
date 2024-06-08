#include<iostream>
#include<memory>
using namespace std;

class os_system{

    public:
        os_system(){};
        ~os_system(){};
        virtual void operation() = 0;
};

class linux_system : public os_system{
    public:
        void operation() override{
            cout << "Setting linux system." << endl;
        }
};

class windows_system : public os_system{
    public:
        void operation() override {
            cout << "Setting windows system." << endl;
        }
};

class computer{
    public:
        
        std::shared_ptr<os_system> os_system_config = nullptr;
        computer(){};
        computer(std::shared_ptr<os_system> os_system_setting) : os_system_config(os_system_setting){};
        ~computer(){};

        virtual void operation() = 0;

};

class Dell_computer : public computer{
    public:
        Dell_computer(std::shared_ptr<os_system> &os_system_setup) : computer(os_system_setup){};
        ~Dell_computer(){};
        void operation() override{
            cout << "Turn on Dell computer." << endl;
            os_system_config->operation();
        }
};

class Gigabyte_computer : public computer{
    public:
        Gigabyte_computer(std::shared_ptr<os_system> &os_system_setup) : computer(os_system_setup){};
        ~Gigabyte_computer(){};
        void operation() override{
            cout << "Turn on Gigabyte computer." << endl;
            os_system_config->operation();
        }
};

int main(){

    std::shared_ptr<os_system> os_setting = std::make_shared<linux_system>();
    std::shared_ptr<computer> computer_product = std::make_shared<Dell_computer>(os_setting);
    computer_product->operation();
    return 0;
}
