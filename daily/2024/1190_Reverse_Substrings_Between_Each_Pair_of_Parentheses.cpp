#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int> sta;
        for (int i = 0; i < n; i++){
            if (s[i] == '(') sta.push(i);
            else if (s[i] == ')'){
                reverse(s.begin()+sta.top()+1, s.begin()+i);
                sta.pop();
            }
        }
        string ans;
        for (char c : s) if (c != '(' && c != ')') ans += c;
        return sta.empty()? ans : "error";
    }
};

int main(){
    string s = "(abcd)";
    // string s = "(u(love)i)";
    // string s = "(ed(et(oc))el)";
    Solution S;
    cout << S.reverseParentheses(s) << endl;
    return 0;
}