#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    stack<int> positive;
    stack<int> negative;
    
    MyQueue() {}
    
    void push(int x) {
        negative.push(x);
    }
    
    int pop() {
        if (positive.empty()){
            while(!negative.empty()){
                positive.push(negative.top());
                negative.pop();
            }
        }
        if (positive.empty()) return -1;
        int ans = positive.top();
        positive.pop();
        return ans;
    }
    
    int peek() {
        if (positive.empty()){
            while(!negative.empty()){
                positive.push(negative.top());
                negative.pop();
            }
        }
        return positive.empty()? -1 : positive.top();
    }
    
    bool empty() {
        return positive.empty() && negative.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main(){
    MyQueue* myQueue = new MyQueue();
    myQueue->push(1);
    myQueue->push(2);
    cout << myQueue->peek() << endl;
    cout << myQueue->pop() << endl;
    cout << myQueue->empty() << endl;
    return 0;
}