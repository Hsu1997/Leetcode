#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverse_graph(n, vector<int>());
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++){
            vector<int> node = graph[i];
            for (int neighbor : node){
                reverse_graph[neighbor].push_back(i);
                indegree[i]++;
            }
        }
        vector<bool> safe(n, false);
        queue<int> que;
        for (int i = 0; i < n; i++) if (indegree[i] == 0) que.push(i), safe[i] = true;
        while(!que.empty()){
            int temp = que.front();
            que.pop();
            for (int from : reverse_graph[temp]){
                indegree[from]--;
                if (indegree[from] == 0) que.push(from), safe[from] = true;
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) if (safe[i]) ans.push_back(i);
        return ans;
    }
};

int main(){
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    // vector<vector<int>> graph = {{1,2,3,4},{1,2},{3,4},{0,4},{}};
    Solution S;
    vector<int> ans = S.eventualSafeNodes(graph);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}