#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for (auto i : s){
            if (i == '(' || i == '[' || i =='{'){
                sta.push(i);
            }
            else{
                if (i == ')' && (sta.empty() || sta.top() != '(')) return false;
                if (i == ']' && (sta.empty() || sta.top() != '[')) return false;
                if (i == '}' && (sta.empty() || sta.top() != '{')) return false;
                sta.pop();
            }
        }
        return sta.empty();
    }
};

int main(){
    // string s = "()";
    // string s = "()[]{}";
    string s = "(]";
    Solution S;
    cout << S.isValid(s) << endl;
    return 0;
}