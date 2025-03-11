#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> create_graph(int n, vector<vector<int>>& edges){
        vector<vector<int>> graph(n);
        for (auto edge : edges){
            graph[edge[0]-1].push_back(edge[1]-1);
            graph[edge[1]-1].push_back(edge[0]-1);
        }
        return graph;
    }
    vector<int> find_all_connected(vector<vector<int>>& graph, int n, int i){
        vector<bool> visited(n, false);
        queue<int> que;
        que.push(i);
        visited[i] = true;
        vector<int> nodes;
        while(!que.empty()){
            int node = que.front();
            que.pop();
            nodes.push_back(node);
            for (int neighbor : graph[node]){
                if (!visited[neighbor]){
                    que.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        return nodes;
    }
    bool is_bipartite(vector<vector<int>>& graph, vector<int>& nodes){
        unordered_map<int,int> node_to_idx;
        for (int i = 0; i < nodes.size(); i++) node_to_idx[nodes[i]] = i;
        vector<int> colors(graph.size(), -1);
        for (int i : nodes){
            if (colors[i] == -1){
                queue<int> que;
                que.push(i);
                colors[i] = 0;
                while(!que.empty()){
                    int node = que.front();
                    que.pop();
                    for (int neighbor : graph[node]){
                        if (node_to_idx.find(neighbor) == node_to_idx.end()) continue;
                        if (colors[neighbor] == -1){
                            colors[neighbor] = 1 - colors[node];
                            que.push(neighbor);
                        }
                        else{
                            if (colors[neighbor] == colors[node]) return false;
                        }
                    }
                }
            }
        }
        return true;
    }
    int find_largest_group(vector<vector<int>>& graph, int node){
        queue<int> que;
        vector<bool> visited(graph.size(), false);
        que.push(node);
        visited[node] = true;
        int group = 0;
        while(!que.empty()){
            int k = que.size();
            while(k--){
                int node = que.front();
                que.pop();
                for (int neighbor : graph[node]){
                    if (visited[neighbor]) continue;
                    visited[neighbor] = true;
                    que.push(neighbor);
                }
            }
            group++;
        }
        return group;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph = create_graph(n, edges);
        vector<bool> visited(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++){
            if (!visited[i]){
                vector<int> connected = find_all_connected(graph, n, i);
                if (!is_bipartite(graph, connected)) return -1;
                int temp_max = 0;
                for (int node : connected){
                    visited[node] = true;
                    temp_max = max(temp_max, find_largest_group(graph, node));
                }
                ans += temp_max;
            }
        }
        return ans;
    }
};

int main(){
    int n = 6;
    vector<vector<int>> edges = {{1,2},{1,4},{1,5},{2,6},{2,3},{4,6}};
    // int n = 3;
    // vector<vector<int>> edges = {{1,2},{2,3},{3,1}};
    // int n = 26;
    // vector<vector<int>> edges = {{9,16},{8,3},{20,21},{12,16},{14,3},{7,21},{22,3},{22,18},{11,16},{25,4},{2,4},{14,21},{23,3},{17,3},{2,16},{24,16},{13,4},{10,21},{7,4},{9,18},{14,18},{14,4},{14,16},{1,3},{25,18},{17,4},{1,16},{23,4},{2,21},{5,16},{24,18},{20,18},{19,16},{24,21},{9,3},{24,3},{19,18},{25,16},{19,21},{6,3},{26,18},{5,21},{20,16},{2,3},{10,18},{26,16},{8,4},{11,21},{23,16},{13,16},{25,3},{7,18},{19,3},{20,4},{26,3},{23,18},{15,18},{17,18},{10,16},{26,21},{23,21},{7,16},{8,18},{10,4},{24,4},{7,3},{11,18},{9,4},{26,4},{13,21},{22,16},{22,21},{20,3},{6,18},{9,21},{10,3},{22,4},{1,18},{25,21},{11,4},{1,21},{15,3},{1,4},{15,16},{2,18},{13,3},{8,21},{13,18},{11,3},{15,21},{8,16},{17,16},{15,4},{12,3},{6,4},{17,21},{5,18},{6,16},{6,21},{12,4},{19,4},{5,3},{12,21},{5,4}};
    Solution S;
    cout << S.magnificentSets(n, edges) << endl;
    return 0;
}