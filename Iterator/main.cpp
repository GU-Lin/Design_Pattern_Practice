#include<iostream>
#include<memory>
#include<vector>
using namespace std;

class auto_iterator{
    public:
        int curr = 0;
        auto_iterator(){};
        ~auto_iterator(){};
        virtual bool has_next() = 0;
        virtual double next() = 0;
        virtual int data_size() = 0;
};

class vector_iterator : public auto_iterator{
    public:
        
        vector<double> *m_data;
        vector_iterator(vector<double> *data):m_data(data){
            curr = 0;
        }
        ~vector_iterator(){};
        bool has_next() override {
            return curr < m_data->size();
        }

        int data_size() override{
            return m_data->size();
        }

        double next() override{
            return m_data->at(curr++);
        }
};

class Aggregate {
public:
    ~Aggregate(){};
    virtual std::shared_ptr<auto_iterator> createIterator(vector<double> *data) = 0;
};

class ConcreteAggregate : public Aggregate{
    public:
        ConcreteAggregate(){};
        ~ConcreteAggregate(){};
        
        std::shared_ptr<auto_iterator> createIterator(vector<double> *data) override{
            return make_shared<vector_iterator>(data);
        }
};

int main() {

vector<double> *v1 = new vector<double>;
v1->push_back(0);
v1->push_back(1.5);
v1->push_back(-2.7);
v1->push_back(3.5);
v1->push_back(6);
v1->push_back(5);
v1->push_back(1.66);


ConcreteAggregate concrete_aggregate;
shared_ptr<auto_iterator> iter = concrete_aggregate.createIterator(v1);

while(iter->has_next()){
    cout << iter->next() << endl;
}

v1->push_back(2);
while(iter->has_next()){
    cout << iter->next() << endl;
}

return 0;
}