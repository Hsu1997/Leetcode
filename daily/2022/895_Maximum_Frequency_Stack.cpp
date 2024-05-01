#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class FreqStack {
public:
    unordered_map<int,int> count;
    unordered_map<int,vector<int>> table;
    int max_count;
    
    FreqStack() {
        max_count = 0;
    }
    
    void push(int val) {
        int fre = ++count[val];
        if (fre > max_count) max_count = fre;
        table[fre].push_back(val);
    }
    
    int pop() {
        int ans = table[max_count].back();
        table[max_count].pop_back();
        count[ans]--;
        if (table[max_count].empty()) max_count--;
        cout << ans << " ";
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

// [[],[4],[0],[9],[3],[4],[2],[],[6],[],[1],[],[1],[],[4],[],[],[],[],[],[]]
int main(){
    FreqStack* obj = new FreqStack();
    obj->push(4);
    obj->push(0);
    obj->push(9);
    obj->push(3);
    obj->push(4);
    obj->push(2);
    obj->pop();
    obj->push(6);
    obj->pop();
    obj->push(1);
    obj->pop();
    obj->push(1);
    obj->pop();
    obj->push(4);
    obj->pop();
    obj->pop();
    obj->pop();
    obj->pop();
    obj->pop();
    obj->pop();
    cout << endl;
    return 0;
}