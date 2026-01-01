#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    unordered_map<string, string> mp;
    unordered_map<string, bool> memo;

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (string& s : allowed) mp[s.substr(0,2)] += s.substr(2,1);
        // for (auto [s1, s2] : m) cout << s1 << " : " << s2 << endl;
        int n = bottom.length();
        return dfs(bottom);
    }

    bool dfs(string& row){
        int n = row.length();
        if (n == 1) return memo[row] = true;
        if (memo.count(row)) return memo[row];
        string curr;
        vector<string> next_row;
        buildNextRow(row, 0, curr, next_row);
        for (string nr : next_row){
            if (dfs(nr)) return memo[row] = true;
        }
        return memo[row] = false;
    }

    void buildNextRow(string& row, int idx, string& curr, vector<string>& next_row){
        int n = row.length();
        if (idx == n - 1) next_row.push_back(curr);
        string key;
        key += row[idx];
        key += row[idx + 1];
        for (char c : mp[key]){
            curr += c;
            buildNextRow(row, idx + 1, curr, next_row);
            curr.pop_back();
        }
    }
};

int main(){
    string bottom = "BCD";
    vector<string> allowed = {"BCC","CDE","CEA","FFF"};
    // string bottom = "AAAA";
    // vector<string> allowed = {"AAB","AAC","BCD","BBE","DEF"};
    Solution S;
    cout << S.pyramidTransition(bottom, allowed) << endl;
    return 0;
}