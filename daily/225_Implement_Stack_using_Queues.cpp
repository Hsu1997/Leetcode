#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
    queue<int> que;
    MyStack() {
        
    }
    
    void push(int x) {
        que.push(x);
    }
    
    int pop() {
        int n = que.size();
        for (int i = 0; i < n - 1; i++){
            que.push(que.front());
            que.pop();
        }
        int ans = que.front();
        que.pop();
        cout << ans << endl;
        return ans;
    }
    
    int top() {
        int n = que.size();
        for (int i = 0; i < n - 1; i++){
            que.push(que.front());
            que.pop();
        }
        int ans = que.front();
        que.push(que.front());
        que.pop();
        cout << ans << endl;
        return ans;
    }
    
    bool empty() {
        bool ans = (que.empty())? true:false;
        cout << ans << endl;
        return ans;
    }
};



int main(){
    MyStack *myStack = new MyStack();
    myStack->push(1);
    myStack->push(2);
    myStack->top(); // return 2
    myStack->pop(); // return 2
    myStack->empty(); // return False
}