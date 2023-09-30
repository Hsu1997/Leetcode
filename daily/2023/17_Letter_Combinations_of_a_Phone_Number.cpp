#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string s;
    int n;
    unordered_map<char,vector<char>> m;
    vector<string> ans;

    void dfs(string& temp, int pos){
        if (pos == n) ans.push_back(temp);

        for (auto i : m[s[pos]]){
            temp.push_back(i);
            dfs(temp, pos+1);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return ans;
        s = digits;
        n = s.length();
        m = {
            {'2', {'a','b','c'}},
            {'3', {'d','e','f'}},
            {'4', {'g','h','i'}},
            {'5', {'j','k','l'}},
            {'6', {'m','n','o'}},
            {'7', {'p','q','r','s'}},
            {'8', {'t','u','v'}},
            {'9', {'w','x','y','z'}}
        };
        string temp;
        dfs(temp, 0);
        return ans;
    }
};

int main(){
    string digits = "23";
    Solution S;
    vector<string> ans = S.letterCombinations(digits);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}