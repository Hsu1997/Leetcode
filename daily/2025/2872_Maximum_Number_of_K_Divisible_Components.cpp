#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int dfs(int node, int parents, vector<vector<int>>& graph, vector<int>& values, int k, int& component){
        int total = values[node] % k;
        for (auto neighbor : graph[node]){
            if (neighbor != parents) total = (total + dfs(neighbor, node, graph, values, k, component)) % k;
        }
        if (total == 0) component++;
        return total;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        int component = 0;
        vector<vector<int>> graph(n);
        for (vector<int>& edge : edges){
            int a = edge[0];
            int b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        dfs(0, -1, graph, values, k, component);
        return component;
    }
};

int main(){
    int n = 5;
    vector<vector<int>> edges = {{0,2},{1,2},{1,3},{2,4}};
    vector<int> values = {1,8,1,4,4};
    int k = 6;
    // int n = 7;
    // vector<vector<int>> edges = {{0,1},{0,2},{1,3},{1,4},{2,5},{2,6}};
    // vector<int> values = {3,0,6,1,5,2,1};
    // int k = 3;
    // int n = 7;
    // vector<vector<int>> edges = {{0,1},{0,2},{1,3},{1,4},{2,5},{2,6}};
    // vector<int> values = {1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000};
    // int k = 7;
    Solution S;
    cout << S.maxKDivisibleComponents(n, edges, values, k) << endl;
    return 0;
}