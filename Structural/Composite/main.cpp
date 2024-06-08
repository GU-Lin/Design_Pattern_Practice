#include <iostream>
#include <memory>
#include <vector>
using namespace std;

struct content {
    public:
        string name;
        content* parent = nullptr; // 父節點
        content() {};
        virtual ~content() {};
        virtual void info() = 0;
        virtual void set_content(const string& in_content) {
            // 默認實現，不做任何操作
        }
        string get_full_number() {
            if (parent == nullptr) {
                return std::to_string(get_local_number()); // 根節點沒有前綴
            } else {
                return parent->get_full_number() + "-" + std::to_string(get_local_number());
            }
        }
        virtual int get_local_number() {
            return 0; // 根據需要在派生類中實現
        }
};

struct chapter : public content {
    int local_number;
    chapter(string title) {
        name = title;
    }
    void info() override {
        cout << get_full_number() << " : " << name << endl;
    }
    int get_local_number() override {
        return local_number;
    }
};

struct chapter_with_sub : public content {
    public:
        vector<shared_ptr<chapter_with_sub>> record;
    
        int local_number;
        chapter_with_sub(string title) {
            name = title;
        }
        void set_content(const string& in_content) override {
            auto temp = make_shared<chapter_with_sub>(in_content);
            temp->parent = this;
            temp->local_number = record.size() + 1;
            record.push_back(temp);
        }
        void info() override {
            cout << get_full_number() << " : " << name << endl;
            for (auto& temp : record) {
                temp->info();
            }
        }
        int get_local_number() override {
            return local_number;
        }
};

void Book(const vector<shared_ptr<content>>& content_record) {
    for (const auto& temp : content_record) {
        temp->info();
    }
}

int main() {
    auto ch1 = make_shared<chapter>("Hello World");
    ch1->local_number = 1;
    auto ch2 = make_shared<chapter_with_sub>("Factory");
    ch2->local_number = 2;
    ch2->set_content("Simple Factory");
    ch2->set_content("Factory Pattern");
    ch2->set_content("Abstract Pattern");
    ch2->record[0]->set_content("Example");
    ch2->record[0]->record[0]->set_content("Example");
    ch2->record[1]->set_content("Example");
    vector<shared_ptr<content>> book = {ch1, ch2};
    Book(book);
    return 0;
}
