#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> count;
    // vector<bool> visited;
    vector<vector<int>> edge;
    vector<int> ans;
    string labels;
    
    void dfs(int node){
        ans[node] = 1;
        int temp = count[labels[node]-'a'];
        count[labels[node]-'a']++;
        for (auto i : edge[node]) if (ans[i] == 0) dfs(i);
        ans[node] = count[labels[node]-'a'] - temp;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string _labels) {
        count = vector<int>(26,0);
        edge = vector<vector<int>>(n, vector<int>());
        ans = vector<int>(n, 0);
        labels = _labels;

        for (auto i : edges){
            edge[i[0]].push_back(i[1]);
            edge[i[1]].push_back(i[0]);
        }

        dfs(0);

        return ans;
    }
};

int main(){
    // int n = 7;
    // vector<vector<int>> edges = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
    // string labels = "abaedcd";
    // int n = 4;
    // vector<vector<int>> edges = {{0,1},{1,2},{0,3}};
    // string labels = "bbbb";
    int n = 5;
    vector<vector<int>> edges = {{0,1},{0,2},{1,3},{0,4}};
    string labels = "aabab";

    Solution S;
    vector<int> ans = S.countSubTrees(n, edges, labels);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}