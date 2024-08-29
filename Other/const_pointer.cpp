#include <iostream>

void printValue(const int* ptr) {
    std::cout << "Value: " << *ptr << std::endl;
    // *ptr = 20;  // 錯誤: 無法修改指針指向的內容
}

int main() {
    int value = 10;
    const int* ptr = &value;
    
    printValue(ptr);  // 輸出: Value: 10
    value = 100;
    printValue(ptr);
    
    // // *ptr = 20;  // 錯誤: 無法修改指針指向的內容
    // int newValue = 30;
    // ptr = &newValue;  // 可以修改指針指向的對象
    
    // std::cout << "New value: " << *ptr << std::endl;  // 輸出: New value: 30
    return 0;
}