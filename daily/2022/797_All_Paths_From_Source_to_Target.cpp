#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void dfs(vector<vector<int>>& graph, int node, vector<int> path){
        for (auto i : graph[node]){
            if (i == n-1) ans.push_back(path);
            else{
                path.push_back(i);
                dfs(graph, i, path);
                path.pop_back();
            }
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        dfs(graph, 0, {0});
        for (int i = 0; i < ans.size(); i++) ans[i].push_back(n-1);
        return ans;
    }
};

int main(){
    // vector<vector<int>> graph = {{1,2},{3},{3},{}};
    vector<vector<int>> graph = {{4,3,1},{3,2,4},{3},{4},{}};
    Solution S;
    vector<vector<int>> ans = S.allPathsSourceTarget(graph);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}