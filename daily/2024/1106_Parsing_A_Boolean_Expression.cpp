#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> sta;
        for (char c : expression){
            if (c == ',' || c == '(') continue;
            if (c != ')') sta.push(c);
            else{
                vector<bool> temp;
                while(!sta.empty() && sta.top() != '&' && sta.top() != '|' && sta.top() != '!'){
                    temp.push_back(sta.top() == 't'? true : false);
                    sta.pop();
                }
                bool curr = temp[0];
                if (sta.top() == '&'){
                    for (int i = 1; i < temp.size(); i++) curr &= temp[i];
                }
                else if (sta.top() == '|'){
                    for (int i = 1; i < temp.size(); i++) curr |= temp[i];
                }
                else{
                    curr ^= true;
                }
                sta.pop();
                sta.push(curr? 't' : 'f');
            }
        }
        return sta.top() == 't'? true : false;
    }
};

int main(){
    string expression = "&(|(f))";
    // string expression = "|(f,f,f,t)";
    // string expression = "!(&(f,t))";
    Solution S;
    cout << S.parseBoolExpr(expression) << endl;
    return 0;
}