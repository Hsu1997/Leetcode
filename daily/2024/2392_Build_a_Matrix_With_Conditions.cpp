#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topological_sort(vector<vector<int>>& conditions, int k){
        vector<vector<int>> edge(k+1);
        vector<int> indegree(k+1, 0);
        for (auto condition : conditions){
            edge[condition[0]].push_back(condition[1]);
            indegree[condition[1]]++;
        }
        vector<int> topological_sort;
        queue<int> que;
        for (int i = 1; i <= k; i++) if (indegree[i] == 0) que.push(i);
        while(!que.empty()){
            int temp = que.front();
            que.pop();
            topological_sort.push_back(temp);
            for (int neighbor : edge[temp]){
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) que.push(neighbor);
            }
        }
        return topological_sort;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> row_topological_sort = topological_sort(rowConditions, k);
        vector<int> col_topological_sort = topological_sort(colConditions, k);
        // for (auto i : row_topological_sort) cout << i << " ";
        // cout << endl;
        // for (auto i : col_topological_sort) cout << i << " ";
        // cout << endl;
        if (row_topological_sort.size() != k || col_topological_sort.size() != k) return {};
        vector<vector<int>> ans(k, vector<int>(k, 0));
        unordered_map<int,pair<int,int>> m;
        for (int i = 0; i < k; i++){
            m[row_topological_sort[i]].first = i;
            m[col_topological_sort[i]].second = i;
        }
        for (int i = 1; i <= k; i++){
            ans[m[i].first][m[i].second] = i;
        }
        return ans;
    }
};

int main(){
    // int k = 3;
    // vector<vector<int>> rowConditions = {{1,2},{3,2}};
    // vector<vector<int>> colConditions = {{2,1},{3,2}};
    int k = 3;
    vector<vector<int>> rowConditions = {{1,2},{2,3},{3,1},{2,3}};
    vector<vector<int>> colConditions = {{2,1}};
    Solution S;
    vector<vector<int>> ans = S.buildMatrix(k, rowConditions, colConditions);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}