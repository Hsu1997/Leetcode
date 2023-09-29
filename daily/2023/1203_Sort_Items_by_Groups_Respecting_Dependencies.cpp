#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool detect_cycle(vector<unordered_set<int>>& group_edge, vector<int>& color, int i){
        // cout << "detect " << i << endl;
        color[i] = 1;
        for (auto neighbor : group_edge[i]){
            if (color[neighbor] == 1) return true;
            if (color[neighbor] == 0 && detect_cycle(group_edge, color, neighbor)) return true;
        }
        color[i] = 2;
        return false;
    }

    void dfs(vector<unordered_set<int>>& group_edge, vector<bool>& visited, int i, stack<int>& s){
        visited[i] = true;
        for (auto neighbor : group_edge[i]){
            if (!visited[neighbor]) dfs(group_edge, visited, neighbor, s);
        }
        s.push(i);
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for (int i = 0; i < n; i++){
            if (group[i] == -1) group[i] = m++;
        }
        // for (int i = 0; i < n; i++){
        //     cout << i << " " << group[i] << " : ";
        //     for (auto j : beforeItems[i]) cout << j << " ";
        //     cout << endl;
        // }
        vector<unordered_set<int>> group_edge(m);
        for (int i = 0; i < n; i++){
            for (auto e : beforeItems[i]) if (group[e] != group[i]) group_edge[group[i]].insert(group[e]);
        }
        // for (int i = 0; i < m; i++){
        //     cout << "group " << i << " : ";
        //     for (auto e : group_edge[i]) cout << e << " ";
        //     cout << endl;
        // }
        vector<int> color(m, 0);
        for (int i = 0; i < m; i++){
            if (color[i] == 0) if (detect_cycle(group_edge, color, i)) return {};
        }
        vector<bool> visited(m, false);
        stack<int> s;
        for (int i = 0; i < m; i++){
            if (!visited[i]) dfs(group_edge, visited, i, s);
        }
        vector<int> topological_group_sort;
        while(!s.empty()){
            topological_group_sort.push_back(s.top());
            s.pop();
        }
        // for (auto i : topological_group_sort) cout << i << " ";
        // cout << endl;
        vector<vector<int>> each_group(m);
        for (int i = 0; i < n; i++) each_group[group[i]].push_back(i);
        // for (auto i : each_group){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }
        visited = vector<bool>(n, false);
        vector<unordered_set<int>> group_inner_edge(n);
        for (int i = 0; i < n; i++){
            for (auto j : beforeItems[i]) if (group[i] == group[j]) group_inner_edge[i].insert(j);
        }
        int temp = 0;
        // for (auto i : group_inner_edge){
        //     cout << temp++ << " : ";
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }
        
        vector<int> inner_color(n, 0);
        for (int i = 0; i < n; i++){
            if (inner_color[i] == 0) if (detect_cycle(group_inner_edge, inner_color, i)) return {};
        }

        vector<int> ans;
        for (int i : topological_group_sort){
            for (auto j : each_group[i]){
                if (!visited[j]) dfs(group_inner_edge, visited, j, s);
            }
            while(!s.empty()){
                ans.push_back(s.top());
                // cout << s.top() << " ";
                s.pop();
            }
            // cout << endl;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    int n = 8;
    int m = 2;
    vector<int> group = {-1,-1,1,0,0,1,0,-1};
    vector<vector<int>> beforeItems = {{},{6},{5},{6},{3,6},{},{},{}};
    // vector<vector<int>> beforeItems = {{},{6},{5},{6},{3},{},{4},{}};
    Solution S;
    vector<int> ans = S.sortItems(n, m, group, beforeItems);
    for (auto i : ans) cout << i <<  " ";
    cout << endl;
    return 0;
}