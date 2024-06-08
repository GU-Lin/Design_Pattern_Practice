#include <iostream>

class EagerSingleton {
public:
    // 刪除拷貝構造函數和賦值操作符，防止多個實例
    EagerSingleton(const EagerSingleton&) = delete;
    EagerSingleton& operator=(const EagerSingleton&) = delete;

    // 提供全局訪問點
    static EagerSingleton& getInstance() {
        return instance;
    }

    void showMessage() {
        std::cout << "Hello, I am an Eager Singleton!" << std::endl;
    }

private:
    // 私有構造函數，防止外界實例化
    EagerSingleton() {
        std::cout << "EagerSingleton instance created." << std::endl;
    }

    // 靜態成員變量，類加載時即創建
    static EagerSingleton instance;
};

// 初始化靜態成員變量
EagerSingleton EagerSingleton::instance;

int main() {
    // 獲取唯一的 EagerSingleton 實例
    EagerSingleton& singleton = EagerSingleton::getInstance();
    EagerSingleton& singleton1 = EagerSingleton::getInstance();
    singleton.showMessage();

    return 0;
}
