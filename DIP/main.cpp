#include<iostream>
using namespace std;

class Payment{
    public:
        virtual void pay() = 0;
        virtual ~Payment(){};
};

class QR_Code_Payment : public Payment{
    public:
        void pay() override{
            cout << "QR code pay" << endl;
        }
};

class Credit_Card_Payment : public Payment{
    public:
        void pay() override{
            cout << "Credit card pay" << endl;
        }
};

class Cash_Payment : public Payment{
    public:
        void pay() override{
            cout << "Cash card pay" << endl;
        }
};

class Pay{
    public:
        void pay(Payment &payment){
            payment.pay();
        }
};


int main(){
    Pay* User = new Pay;
    Credit_Card_Payment credit_card;
    QR_Code_Payment QR_code;
    Cash_Payment Cash;
    User->pay(credit_card);
    User->pay(QR_code);
    User->pay(Cash);
    return 0;
}