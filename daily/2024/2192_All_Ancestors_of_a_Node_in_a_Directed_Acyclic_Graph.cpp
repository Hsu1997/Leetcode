#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void dfs(vector<unordered_set<int>>& d, vector<vector<int>>& e, int i){
        for (int neighbor : e[i]){
            if (d[neighbor].empty()) dfs(d, e, neighbor);
            for (auto k : d[neighbor]) d[i].insert(k);
            d[i].insert(neighbor);
        }
        return;
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> d(n);
        vector<vector<int>> e(n);
        for (auto i : edges){
            e[i[1]].push_back(i[0]);
        }
        // for (int i = 0; i < n; i++){
        //     cout << i << " : ";
        //     for (auto j : e[i]) cout << j << " ";
        //     cout << endl;
        // }
        for (int i = 0; i < n; i++){
            if (d[i].empty()) dfs(d, e, i);
        }
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; i++){
            ans[i] = vector(d[i].begin(), d[i].end());
            sort(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};

int main(){
    int n = 8;
    vector<vector<int>> edges = {{0,3},{0,4},{1,3},{2,4},{2,7},{3,5},{3,6},{3,7},{4,6}};
    // int n = 5;
    // vector<vector<int>> edges = {{0,1},{0,2},{0,3},{0,4},{1,2},{1,3},{1,4},{2,3},{2,4},{3,4}};
    Solution S;
    vector<vector<int>> ans = S.getAncestors(n, edges);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}