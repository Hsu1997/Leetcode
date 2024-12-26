#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<vector<int>> graph1 = create_graph(edges1);
        vector<vector<int>> graph2 = create_graph(edges2);
        auto [f1, _d1] = bfs(graph1, 0);
        auto [f2, _d2] = bfs(graph2, 0);
        auto [_f1, d1] = bfs(graph1, f1);
        auto [_f2, d2] = bfs(graph2, f2);
        return max({d1, d2, (d1+1)/2 + (d2+1)/2 + 1});
    }
private:
    vector<vector<int>> create_graph(vector<vector<int>>& edges){
        int n = edges.size() + 1;
        vector<vector<int>> graph(n);
        for (auto& e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        return graph;
    }
    pair<int,int> bfs(vector<vector<int>>& graph, int start_node){
        int n = graph.size();
        vector<bool> visited(n, false);
        queue<int> que({start_node});
        visited[start_node] = true;
        int farest_node = -1;
        int diameter = 0;
        while(!que.empty()){
            int s = que.size();
            while(s--){
                int curr = que.front();
                que.pop();
                farest_node = curr;
                for (int neighbor : graph[curr]){
                    if (!visited[neighbor]){
                        visited[neighbor] = true;
                        que.push(neighbor);
                    }
                }
            }
            if (!que.empty()) diameter++;
        }
        return {farest_node, diameter};
    }
};

int main(){
    vector<vector<int>> edges1 = {{0,1},{0,2},{0,3}};
    vector<vector<int>> edges2 = {{0,1}};
    // vector<vector<int>> edges1 = {{0,1},{0,2},{0,3},{2,4},{2,5},{3,6},{2,7}};
    // vector<vector<int>> edges2 = {{0,1},{0,2},{0,3},{2,4},{2,5},{3,6},{2,7}};
    // vector<vector<int>> edges1 = {};
    // vector<vector<int>> edges2 = {};
    // vector<vector<int>> edges1 = {{0,1},{2,0},{3,2},{3,6},{8,7},{4,8},{5,4},{3,5},{3,9}};
    // vector<vector<int>> edges2 = {{0,1},{0,2},{0,3}};
    Solution S;
    cout << S.minimumDiameterAfterMerge(edges1, edges2) << endl;
    return 0;
}