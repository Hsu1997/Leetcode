#include <iostream>
#include <vector>

using namespace std;

class CustomStack {
public:
    vector<int> sta;
    int index;

    CustomStack(int maxSize) {
        sta.resize(maxSize);
        index = 0;
    }
    
    void push(int x) {
        if (index == sta.size()) return;
        sta[index++] = x;
        return;
    }
    
    int pop() {
        if (index == 0) return -1;
        return sta[--index];
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < min(index, k); i++){
            sta[i] += val;
        }
    }
};

int main(){
    CustomStack* stk = new CustomStack(3); // Stack is Empty []
    stk->push(1);
    stk->push(2);
    cout << stk->pop() << " ";
    stk->push(2);
    stk->push(3);
    stk->push(4);
    stk->increment(5, 100);
    stk->increment(2, 100);
    cout << stk->pop() << " ";
    cout << stk->pop() << " ";
    cout << stk->pop() << " ";
    cout << stk->pop() << " ";
    cout << endl;
    return 0;
}