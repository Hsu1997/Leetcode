#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> out_degree_count(n, 0);
        vector<vector<int>> source_nodes(n);
        vector<int> ans;
        for (int source = 0; source < n; source++){
            vector<int>& edges = graph[source];
            out_degree_count[source] = edges.size();
            for (auto& des : edges) source_nodes[des].push_back(source);
        }
        queue<int> zero_outdegree;
        for (int i = 0; i < n; i++) if (out_degree_count[i] == 0) zero_outdegree.push(i);
        while(!zero_outdegree.empty()){
            int curr = zero_outdegree.front();
            zero_outdegree.pop();
            ans.push_back(curr);
            for (auto& source : source_nodes[curr]){
                out_degree_count[source]--;
                if (out_degree_count[source] == 0) zero_outdegree.push(source);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    // vector<vector<int>> graph = {{1,2,3,4},{1,2},{3,4},{0,4},{}};
    Solution S;
    vector<int> ans = S.eventualSafeNodes(graph);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}