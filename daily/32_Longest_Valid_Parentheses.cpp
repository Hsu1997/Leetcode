#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.length() < 2) return 0;
        vector<int> count(s.length(), 0);
        int ans = 0;

        if (s[0] == '(' && s[1] == ')') count[1] = 2, ans = 2;
        
        for (int i = 2; i < s.length(); i++){
            if (s[i] == '(') continue;
            if (s[i-1] == '(') count[i] = count[i-2]+2;
            else{
                if ((i - 1 - count[i-1] >= 0) && s[i - 1 - count[i-1]] == '('){
                    count[i] = count[i-1] + 2;
                    if (i - 1 - count[i - 1] - 1 >= 1) count[i] += count[i - 1 - count[i-1] - 1];
                }
                else count[i] = 0;
            }
            ans = max(ans, count[i]);
        }

        // for (int i : count) cout << i << " ";
        // cout << endl;

        return ans;
    }
};

int main(){
    string s = "()";
    Solution S;
    cout << S.longestValidParentheses(s) << endl;
    return 0;
}