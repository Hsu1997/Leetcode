#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> compute_each_target(vector<vector<int>>& graph, int k){
        int n = graph.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++){
            queue<int> que;
            vector<int> visited(n, false);
            que.push(i);
            visited[i] = true;
            for (int p = 0; p <= k; p++){
                int t = que.size();
                while(t--){
                    int curr = que.front();
                    que.pop();
                    ans[i]++;
                    for (auto neighbor : graph[curr]){
                        if (!visited[neighbor]){
                            que.push(neighbor);
                            visited[neighbor] = true;
                        }
                    }
                }
            }
        }
        // for (auto i : ans) cout << i << " ";
        // cout << endl;
        return ans;
    }
    vector<vector<int>> transToGraph(vector<vector<int>>& edges){
        int n = edges.size() + 1;
        vector<vector<int>> graph(n);
        for (auto edge : edges){
            int n1 = edge[0];
            int n2 = edge[1];
            graph[n1].push_back(n2);
            graph[n2].push_back(n1);
        }
        return graph;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        if (k == 0) return vector<int>(edges1.size() + 1, 1);
        vector<vector<int>> g1 = transToGraph(edges1);
        vector<vector<int>> g2 = transToGraph(edges2);
        vector<int> t1 = compute_each_target(g1, k);
        int M = 0;
        if (k == 1) M = 1;
        else{
            vector<int> t2 = compute_each_target(g2, k-1);
            for (auto i : t2) M = max(M, i);
        }
        for (int i = 0; i < t1.size(); i++) t1[i] += M;
        return t1;
    }
};

int main(){
    vector<vector<int>> edges1 = {{0,1},{0,2},{2,3},{2,4}};
    vector<vector<int>> edges2 = {{0,1},{0,2},{0,3},{2,7},{1,4},{4,5},{4,6}};
    int k = 2;
    // vector<vector<int>> edges1 = {{0,1},{0,2},{0,3},{0,4}};
    // vector<vector<int>> edges2 = {{0,1},{1,2},{2,3}};
    // int k = 1;
    Solution S;
    vector<int> ans = S.maxTargetNodes(edges1, edges2, k);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}