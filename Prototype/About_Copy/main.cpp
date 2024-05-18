#include <iostream>
#include <cstring>
using namespace std;
int main(){

    // 原始資料
    int* data1 = new int;
    *data1 = 42;

    // 淺拷貝
    // int* data2 = data1;

    // 深拷貝
    int* data2 = new int;
    *data2 = *data1;

    // 顯示原始資料和拷貝資料
    cout << "Original data1: " << *data1 << endl;
    cout << "Copy data2: " << *data2 << endl;

    // 修改原始資料
    *data1 = 100;

    // 顯示修改後的資料
    cout << "Modified original data1: " << *data1 << endl;
    cout << "After modification, copy data2: " << *data2 << endl;

    cout << data1 << ", " << &data1 <<endl;
    cout << data2 << ", " << &data2 <<endl;
    delete data1;
    // delete data2; // 不能再次刪除，會導致未定義行為
    return 0;       
}