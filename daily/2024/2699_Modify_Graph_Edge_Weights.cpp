#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int shortest_path(int n, vector<vector<pair<int,int>>>& graph, int source, int destination){
        vector<int> shortest(n, INT_MAX);
        shortest[source] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, source});
        while(!pq.empty()){
            auto [dis, node] = pq.top();
            pq.pop();
            if (dis > shortest[node]) continue;
            if (node == destination) return dis;
            for (auto [neighbor, edge_len] : graph[node]){
                if (dis + edge_len < shortest[neighbor]){
                    shortest[neighbor] = dis + edge_len;
                    pq.push({shortest[neighbor], neighbor});
                }
            }
        }
        return shortest[destination];
    }

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<int>> ans;
        vector<vector<pair<int,int>>> graph(n);
        for (auto& e : edges){
            if (e[2] == -1) continue;
            int n1 = e[0];
            int n2 = e[1];
            int v = e[2];
            graph[n1].push_back({n2, v});
            graph[n2].push_back({n1, v});
        }
        int curr_shortest_path = shortest_path(n, graph, source, destination);
        if (curr_shortest_path < target) return {};
        bool finded = (curr_shortest_path == target);
        for (auto& e : edges){
            if (e[2] != -1) continue;
            e[2] = finded? 2e9 : 1;
            int n1 = e[0];
            int n2 = e[1];
            int v = e[2];
            graph[n1].push_back({n2, v});
            graph[n2].push_back({n1, v});
            if (!finded){
                int temp_path = shortest_path(n, graph, source, destination);
                if (temp_path <= target){
                    e[2] += target - temp_path;
                    finded = true;
                }
            }
        }
        return finded? edges : vector<vector<int>>();
    }
};

int main(){
    int n = 5;
    vector<vector<int>> edges = {{4,1,-1},{2,0,-1},{0,3,-1},{4,3,-1}};
    int source = 0;
    int destination = 1;
    int target = 5;
    // int n = 3;
    // vector<vector<int>> edges = {{0,1,-1},{0,2,5}};
    // int source = 0;
    // int destination = 2;
    // int target = 6;
    // int n = 4;
    // vector<vector<int>> edges = {{1,0,4},{1,2,3},{2,3,5},{0,3,-1}};
    // int source = 0;
    // int destination = 2;
    // int target = 6;
    Solution S;
    vector<vector<int>> ans = S.modifiedGraphEdges(n, edges, source, destination, target);
    for (auto i : ans){
        for (int j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}