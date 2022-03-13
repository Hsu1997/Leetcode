#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 0) return true;
        stack<char> sta;
        for (char c : s){
            if (c == '(' || c == '[' || c == '{') sta.push(c);
            else{
                if (c == ')') if (sta.size() == 0 || sta.top() != '(') return false; 
                if (c == ']') if (sta.size() == 0 || sta.top() != '[') return false;
                if (c == '}') if (sta.size() == 0 || sta.top() != '{') return false;
                sta.pop();
            }
        }
        return sta.empty();
    }
};

int main(){
    string s = "]";
    Solution S;
    cout << S.isValid(s) << endl;
    return 0;
}