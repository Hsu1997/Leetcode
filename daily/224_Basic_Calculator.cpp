#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int result = 0;
        // int temp;

        int sign = 1;
        stack<int> sta;
        sta.push(0);

        for (int i = 0; i < s.length(); i++){
            if (s[i] == ' ') continue;
            else if (s[i] == '+') sign = 1;
            else if (s[i] == '-') sign = -1;
            else if (isdigit(s[i])){
                int temp = s[i] - '0';
                while(i+1 < s.length() && isdigit(s[i+1])){
                    i++;
                    temp = temp * 10 + (s[i] - '0');
                }
                result += sign * temp;
                // cout << result << endl;
            }
            else if (s[i] == '('){
                sta.push(result);
                sta.push(sign);
                sign = 1;
                result = 0;
            }
            else if (s[i] == ')'){
                result *= sta.top();
                sta.pop();
                int temp = sta.top();
                sta.pop();
                result += temp;
                // cout << result << endl;
            }
        }
        return result;
    }
};

int main(){
    Solution S;
    // string s = "1 + 1";
    // string s = " 2-1 + 2 ";
    // string s = "(1+(4+5+2)-3)+(6+8)";
    string s = "1 -(-  2)";
    // string s = "2147483647";
    cout << S.calculate(s) << endl;
    return 0;
}