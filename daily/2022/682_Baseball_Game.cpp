#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> S;
        for (string i : ops){
            // cout << i << endl;
            if ((i[0] == '-') || isdigit(i[0])){
                S.push(stoi(i));
                // cout << "push " << S.top() << endl;
            }
            else if (i == "C"){
                // cout << "pop " << S.top() << endl;
                S.pop();
            }
            else if (i == "D"){
                S.push(S.top() * 2);
                // cout << "push " << S.top() << endl;
            }
            else if (i == "+"){
                int a = S.top();
                S.pop();
                int b = S.top();
                S.push(a);
                S.push(a+b);
                // cout << "push " << S.top() << endl; 
            }
        }
        int ans = 0;
        while(!S.empty()){
            ans += S.top();
            S.pop();
        }
        return ans;
    }
};

int main(){
    vector<string> ops = {"5","-2","4","C","D","9","+","+"};
    Solution S;
    cout << S.calPoints(ops) << endl;
    return 0;
}