#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<long long> sta;
        sta.push(0);
        for (char c : s){
            if (c == '(') sta.push(0);
            else{
                long long res = sta.top();
                sta.pop();
                if (res == 0) sta.top() += 1;
                else sta.top() += res * 2;
            }
        }
        return sta.top();
    }
};

int main(){
    string s = "()";
    // string s = "(())";
    // string s = "()()";
    Solution S;
    cout << S.scoreOfParentheses(s) << endl;
    return 0;
}