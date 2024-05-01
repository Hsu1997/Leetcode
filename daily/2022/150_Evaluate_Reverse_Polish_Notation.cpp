#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> s;
        for (string i : tokens){
            // cout << i << endl;
            if (isdigit(i[i.length()-1])) s.push((long)stoi(i));
            else{
                long temp2 = s.top();
                s.pop();
                long temp1 = s.top();
                s.pop();
                if (i[0] == '+') s.push(temp1 + temp2);
                else if (i[0] == '-') s.push(temp1 - temp2);
                else if (i[0] == '*') s.push(temp1 * temp2);
                else s.push(temp1 / temp2);
                // cout << s.top() << " ";
            }
        }
        return s.top();
    }
};

int main(){
    Solution S;
    // vector<string> tokens = {"2","1","+","3","*"};
    // vector<string> tokens = {"4","13","5","/","+"};
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << S.evalRPN(tokens) << endl;
    return 0;
}