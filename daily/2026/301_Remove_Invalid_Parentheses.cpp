#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    unordered_set<string> ans;
    int maxLen = -1;
    int n;

    void dfs(string& s, int left, vector<int>& remainRight, int idx, string& curr){
        if (idx == s.length()){
            if (left == 0){
                int len = curr.length();
                if (len >= maxLen){
                    if (len > maxLen){
                        ans.clear();
                        maxLen = len;
                    }
                    ans.insert(curr);
                }
            }
            return;
        }
        else{
            char c = s[idx];
            if (c != '(' && c != ')'){
                curr += c;
                dfs(s, left, remainRight, idx + 1, curr);
                curr.pop_back();
            }
            else{
                dfs(s, left, remainRight, idx + 1, curr);
                if (c == '('){
                    if (left + 1 <= remainRight[idx]){
                        curr += '(';
                        dfs(s, left + 1, remainRight, idx + 1, curr);
                        curr.pop_back();
                    }
                }
                else{
                    if (left > 0){
                        curr += ')';
                        dfs(s, left - 1, remainRight, idx + 1, curr);
                        curr.pop_back();
                    }
                }
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        n = s.length();
        vector<int> remainRight(n, 0);
        for (int i = n - 2; i >= 0; i--){
            remainRight[i] = remainRight[i + 1] + (s[i + 1] == ')');
        }
        string curr = "";
        dfs(s, 0, remainRight, 0, curr);
        return vector<string>(ans.begin(), ans.end());
    }
};

int main(){
    string s = "()())()";
    // string s = "(a);())()";
    // string s = ")(";
    Solution S;
    vector<string> ans = S.removeInvalidParentheses(s);
    for (string s : ans) cout << s << " ";
    cout << endl;
    return 0;
}