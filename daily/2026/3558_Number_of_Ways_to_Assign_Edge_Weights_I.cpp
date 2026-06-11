#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        if (n < 3) return n / 2;
        vector<vector<int>> graph(n);
        for (auto& edge : edges){
            int a = edge[0] - 1;
            int b = edge[1] - 1;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int depth = 0;
        queue<int> que;
        que.push(0);
        vector<bool> visited(n, false);
        visited[0] = true;
        while(!que.empty()){
            depth++;
            int s = que.size();
            while(s--){
                int curr = que.front();
                que.pop();
                for (int child : graph[curr]){
                    if (visited[child]) continue;
                    que.push(child);
                    visited[child] = true;
                }
            }
        }
        long long ans = 1;
        long long mod = 1e9 + 7;
        for (int d = 2; d < depth; d++){
            ans <<= 1;
            ans %= mod;
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> edges = {{1,2}};
    // vector<vector<int>> edges = {{1,2},{1,3},{3,4},{3,5}};
    Solution S;
    cout << S.assignEdgeWeights(edges) << endl;
    return 0;
}