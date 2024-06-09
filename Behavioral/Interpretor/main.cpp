#include<iostream>
#include<vector>
#include<string>
#include<memory>

using namespace std;

class AbstractExpression{
    public:
        virtual double interpret() const = 0;
        ~AbstractExpression(){};
};

class Number : public AbstractExpression{
    public:
        Number(int a) : num(a){}
        double interpret() const override{
            return num;
        }
    private:
        double num;
};

class Add : public AbstractExpression{
    public:
        Add(unique_ptr<AbstractExpression>a, unique_ptr<AbstractExpression>b):left(std::move(a)),right(std::move(b)){};
        double interpret() const override{
            return (left->interpret() + right->interpret());
        }
        ~Add(){};
    private:
        unique_ptr<AbstractExpression> left;
        unique_ptr<AbstractExpression> right;
};

class Minus : public AbstractExpression{
    public:
        Minus(unique_ptr<AbstractExpression>a, unique_ptr<AbstractExpression>b):left(std::move(a)),right(std::move(b)){};
        double interpret() const override{
            return (left->interpret() - right->interpret());
        }
        ~Minus(){};
    private:
        unique_ptr<AbstractExpression> left;
        unique_ptr<AbstractExpression> right;
};

enum Type { number, 
            plus, 
            minus 
};

struct context{
    Type type_;
    string text_;
    context(Type type, string text):type_(type),text_(text){}
};

vector<context> handle_string(string str){
    vector<context> table;

    for(int i = 0; i <str.size();i++){
        
        switch(str[i]){
            case '+':
                table.push_back(context(Type::plus, "+"));
                break;
            case '-':
                table.push_back(context(Type::minus, "-"));
                break;
            default:
                string temp = to_string(str[i]-'0');
                for(int j = i+1; j <str.size();j++){
                    // cout << "Num is "<<temp << endl;
                    if(isdigit(str[j])){
                        temp += str[j];
                        i++;
                    }else{         
                        table.push_back(context(Type::number, temp));
                        temp = "";
                        break;
                    }
                }
                if(temp!=""){
                    table.push_back(context(Type::number, temp));
                }
                break;
        }
    }
    return table;
};

class Parser {
public:
    Parser(const std::string &input) : input_(input), pos_(0) {}

    std::unique_ptr<AbstractExpression> parse() {
        return parseExpression();
    }

private:
    std::unique_ptr<AbstractExpression> parseExpression() {
        context_ = handle_string(input_);
        std::unique_ptr<AbstractExpression> left = parseNumber();
        std::unique_ptr<AbstractExpression> right = nullptr;
        while(pos_<context_.size()){
            switch(context_[pos_].type_){
                case Type::plus:
                    pos_++;
                    right = parseNumber();
                    left = make_unique<Add>(std::move(left),std::move(right));
                    break;
                case Type::minus:
                    pos_++;
                    right = parseNumber();
                    left = make_unique<Minus>(std::move(left),std::move(right));
                    break;
                default:
                    break;
            }
        }
        return left;
    };

    // 獲取數字
    std::unique_ptr<AbstractExpression> parseNumber() {
        int start = pos_;
        int number = std::stoi(context_[pos_].text_);
        pos_++;
        return std::make_unique<Number>(number);
    }
    vector<context> context_;
    std::string input_;
    size_t pos_;
};


int main(){
    Parser parser("1+8-62");
    auto res = parser.parse();
    cout << res->interpret() << endl;
    return 0;
}
