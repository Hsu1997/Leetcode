#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    int ans;
    string s;
    vector<vector<int>> child;

    int dfs(int node){
        if (child[node].empty()) return 1;
        
        int m1 = 0, m2 = 0;
        for (auto i : child[node]){
            int temp = dfs(i);
            if (s[node] == s[i]) ans = max(ans, temp);
            else{
                if (temp > m1) m2 = m1, m1 = temp;
                else m2 = max(m2, temp);
            }
        }
        ans = max(ans, 1+m1+m2);
        return 1 + m1;
    }

    int longestPath(vector<int>& parent, string _s) {
        ans = 1;
        int n = parent.size();
        if (n == 1) return ans;

        s = _s;
        child = vector<vector<int>>(n, vector<int>());
        for (int i = 1; i < n; i++) child[parent[i]].push_back(i);

        // for (auto i : child){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }
        
        dfs(0);

        return ans;
    }
};

int main(){
    vector<int> parent = {-1,0,0,1,1,2};
    string s = "abacbe";
    // vector<int> parent = {-1,0,0,0};
    // string s = "aabc";
    Solution S;
    cout << S.longestPath(parent, s) << endl;
    return 0;
}