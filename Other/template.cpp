#include <iostream>

using namespace std;

template <typename T>
class Printer {
public:
    void print(T value) {
        std::cout << value << std::endl;
    }
};

template <>
class Printer<const char*> {  // 對 const char* 類型進行特化
public:
    void print(const char* value) {
        std::cout << "String: " << value << std::endl;
    }
};

int main() {
    Printer<int> intPrinter;
    intPrinter.print(42);  // 使用通用模板
    
    Printer<const char*> stringPrinter;
    stringPrinter.print("Hello, World!");  // 使用特化模板
    return 0;
}