#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int>::iterator ptr_push = pushed.begin();
        vector<int>::iterator ptr_pop = popped.begin();
        stack<int> S;
        while(ptr_push != pushed.end()){
            if (*ptr_pop == *ptr_push){
                ptr_push++;
                ptr_pop++;
            }
            else if (!S.empty() && *ptr_pop == S.top()){
                S.pop();
                ptr_pop++;
            }
            else{
                S.push(*ptr_push);
                ptr_push++;
            }
        }
        // if (ptr_pop == popped.end()) return true;
        while(ptr_pop != popped.end()){
            if (*ptr_pop != S.top()){
                return false;
            }
            else{
                S.pop();
                ptr_pop++;
            }
        }
        return true;
    }
};

int main(){
    vector<int> pushed = {0,1,2,3,4};
    vector<int> popped = {0,2,4,3,1};
    Solution S;
    cout << S.validateStackSequences(pushed, popped) << endl;
    return 0;
}