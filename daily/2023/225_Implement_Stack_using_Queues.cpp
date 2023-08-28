#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class MyStack {
public:
    queue<int> que;

    MyStack() {}
    
    void push(int x) {
        que.push(x);
    }
    
    int pop() {
        int k = que.size()-1;
        while(k--){
            que.push(que.front());
            que.pop();
        }
        int ans = que.front();
        que.pop();
        return ans;
    }
    
    int top() {
        int k = que.size()-1;
        while(k--){
            que.push(que.front());
            que.pop();
        }
        int ans = que.front();
        que.push(ans);
        que.pop();
        return ans;
    }
    
    bool empty() {
        return que.empty();
    }
};

int main(){
    MyStack* S = new MyStack();
    S->push(1);
    S->push(2);
    cout << S->top() << endl;
    cout << S->pop() << endl;
    cout << S->empty() << endl;
}
