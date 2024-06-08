#include <iostream>
#include <mutex>

class LazySingleton {
public:
    // 刪除拷貝構造函數和賦值操作符，防止多個實例
    LazySingleton(const LazySingleton&) = delete;
    LazySingleton& operator=(const LazySingleton&) = delete;

    // 提供全局訪問點
    static LazySingleton& getInstance() {
        // 使用雙重檢查鎖定來確保線程安全
        if (instance == nullptr) {
            std::lock_guard<std::mutex> lock(mutex);
            if (instance == nullptr) {
                instance = new LazySingleton();
            }
        }
        return *instance;
    }

    void showMessage() {
        std::cout << "Hello, I am a Lazy Singleton!" << std::endl;
    }

private:
    // 私有構造函數，防止外界實例化
    LazySingleton() {
        std::cout << "LazySingleton instance created." << std::endl;
    }

    // 靜態成員變量和鎖
    static LazySingleton* instance;
    static std::mutex mutex;
};

// 初始化靜態成員變量
LazySingleton* LazySingleton::instance = nullptr;
std::mutex LazySingleton::mutex;

int main() {
    // 獲取唯一的 LazySingleton 實例
    LazySingleton& singleton = LazySingleton::getInstance();
    LazySingleton& singleton1 = LazySingleton::getInstance();
    singleton.showMessage();
    return 0;
}
