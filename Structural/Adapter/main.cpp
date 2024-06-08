#include<iostream>
#include<memory>
#include<vector>
using namespace std;

class Taiwan_Dollars{
    public:
        int dollars;
        void total(int in){
            dollars = in;
        }
};

class Transfer{
    public:
        virtual void transfer(std::shared_ptr<Taiwan_Dollars> &taiwan_Dollars) = 0;
};

class USA_Transfer : public Transfer{
    
    private:
        std::shared_ptr<Taiwan_Dollars> taiwan_Dollars_private = nullptr;
        double USA_dollars = 0;
    public:
        double exchange_rate = 0;
        
        void set_exchange_rate(double in){
            exchange_rate = in;
            cout << "Transfer rate : " <<  exchange_rate << endl;
        }
        void transfer(std::shared_ptr<Taiwan_Dollars> &taiwan_Dollars) override{
            taiwan_Dollars_private = taiwan_Dollars;
            USA_dollars = taiwan_Dollars_private->dollars / exchange_rate;
        }
        void show(){
            cout << "USA dollars : " << USA_dollars << endl;
        }

}; 
TEST_F
int main(){
    std::shared_ptr<Taiwan_Dollars> money = std::make_shared<Taiwan_Dollars>();
    money->total(100);

    std::shared_ptr<USA_Transfer> USA_transfer = std::make_shared<USA_Transfer>();
    USA_transfer->set_exchange_rate(32.145);
    USA_transfer->transfer(money);
    cout << "Taiwan dollars " << money->dollars << endl;
    cout << "---------convert--------" << endl;
    USA_transfer->show();

    return 0;
}
