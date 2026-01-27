#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> graph(n);
        for (auto& e : edges){
            int v1 = e[0];
            int v2 = e[1];
            int w = e[2];
            graph[v1].push_back({v2, w});
            graph[v2].push_back({v1, w * 2});
        }
        vector<int> d(n, INT_MAX);
        d[0] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, 0});
        while(!pq.empty()){
            auto [dis, node] = pq.top();
            pq.pop();
            if (d[node] != dis) continue;
            if (node == n - 1) return dis;
            for (auto& [next, w] : graph[node]){
                if (dis + w < d[next]){
                    d[next] = dis + w;
                    pq.push({d[next], next});
                }
            }
        }
        return -1;
    }
};

int main(){
    int n = 4;
    vector<vector<int>> edges = {{0,1,3},{3,1,1},{2,3,4},{0,2,2}};
    // int n = 4;
    // vector<vector<int>> edges = {{0,2,1},{2,1,1},{1,3,1},{2,3,3}};
    Solution S;
    cout << S.minCost(n, edges) << endl;
    return 0;
}