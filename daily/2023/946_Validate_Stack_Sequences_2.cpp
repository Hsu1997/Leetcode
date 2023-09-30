#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i = 0;
        int j = 0;
        while(i < pushed.size() && j < popped.size()){
            if (pushed[i] == popped[j]) i++,j++;
            else{
                if (!s.empty() && popped[j] == s.top()){
                    s.pop();
                    j++;
                }
                else{
                    s.push(pushed[i]);
                    i++;
                }
            }
        }
        while(!s.empty()){
            if (popped[j] != s.top()) return false;
            else{
                s.pop();
                j++;
            }
        }
        return true;
    }
};

int main(){
    // vector<int> pushed = {1,2,3,4,5};
    // vector<int> popped = {4,5,3,2,1};
    vector<int> pushed = {1,2,3,4,5};
    vector<int> popped = {4,3,5,1,2};
    Solution S;
    cout << S.validateStackSequences(pushed, popped) << endl;
    return 0;
}