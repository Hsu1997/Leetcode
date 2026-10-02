#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string res(n * 2, '.');
        dfs(res, 0, n, n, ans);
        return ans;
    }
    void dfs(string& res, int pos, int cntl, int cntr, vector<string>& ans){
        if (cntl == 0 && cntr == 0){
            ans.push_back(res);
            return;
        }
        if (cntl > 0){
            res[pos] = '(';
            dfs(res, pos + 1, cntl - 1, cntr, ans);
        }
        if (cntr > cntl){
            res[pos] = ')';
            dfs(res, pos + 1, cntl, cntr - 1, ans);
        }
    }
};

int main(){
    int n = 3;
    // int n = 1;
    // int n = 2;
    // int n = 5;
    // int n = 7;
    // int n = 8;
    Solution S;
    vector<string> ans = S.generateParenthesis(n);
    for (string s : ans){
        cout << s << " ";
    }
    cout << endl;
    return 0;
}