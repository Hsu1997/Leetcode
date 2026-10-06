#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int ans = 0;
        for (int start = 0; start < n; start++){
            if (s[start] == ')') continue;
            int cntl = 1;
            int cntr = 0;
            for (int end = start + 1; end < n; end++){
                if (s[end] == '('){
                    cntl++;
                }
                else{
                    cntr++;
                    if (cntr > cntl) break;
                    if (cntr == cntl) ans = max(ans, end - start + 1);
                }
            }
        }
        return ans;
    }
};

int main(){
    string s = "(()";
    // string s = ")()())";
    // string s = "";
    // string s = "()(()";
    // string s = "(())()(()((";
    Solution S;
    cout << S.longestValidParentheses(s) << endl;
    return 0;
}