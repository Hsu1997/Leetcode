#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int ans = -1;
    int min_neighbor = INT_MAX;

    void count_neighbor(vector<vector<pair<int,int>>>& graph, int node, int distanceThreshold){
        vector<bool> visited(graph.size(), false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> que;
        que.push({0, node});
        int neighbor = -1;
        while(!que.empty()){
            if (neighbor == min_neighbor) return;
            auto it = que.top();
            que.pop();
            int acc_weight = it.first;
            int curr_node = it.second;
            if (visited[curr_node]) continue;
            if (acc_weight > distanceThreshold) break;
            visited[curr_node] = true;
            neighbor++;
            for (auto neighbor : graph[curr_node]){
                int to = neighbor.first;
                int weight = neighbor.second;
                if (!visited[to] && acc_weight + weight <= distanceThreshold) que.push({acc_weight + weight, to});
            }
        }
        if (neighbor < min_neighbor) min_neighbor = neighbor, ans = node;
        return;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> graph(n);
        for (auto i : edges){
            int from = i[0];
            int destination = i[1];
            int weight = i[2];
            graph[from].push_back({destination, weight});
            graph[destination].push_back({from, weight});
        }
        for (int i = n-1; i >= 0; i--) count_neighbor(graph, i, distanceThreshold);
        return ans;
    }
};

int main(){
    int n = 4;
    vector<vector<int>> edges = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    int distanceThreshold = 4;
    // int n = 5;
    // vector<vector<int>> edges = {{0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1}};
    // int distanceThreshold = 2;
    // int n = 6;
    // vector<vector<int>> edges = {{0,1,10},{0,2,1},{2,3,1},{1,3,1},{1,4,1},{4,5,10}};
    // int distanceThreshold = 20;
    Solution S;
    cout << S.findTheCity(n, edges, distanceThreshold) << endl;
    return 0;
}