#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for (char c : s){
            if (c == '(' || c == '[' || c == '{') sta.push(c);
            else{
                if (sta.empty()) return false;
                if (c == ')'){
                    if (sta.top() == '(') sta.pop();
                    else return false;
                }
                if (c == ']'){
                    if (sta.top() == '[') sta.pop();
                    else return false;
                }
                if (c == '}'){
                    if (sta.top() == '{') sta.pop();
                    else return false;
                }
            }
        }
        return sta.empty();
    }
};

int main(){
    string s = "()";
    // string s = "()[]{}";
    // string s = "(]";
    // string s = "([])";
    // string s = "([)]";
    Solution S;
    cout << S.isValid(s) << endl;
    return 0;
}