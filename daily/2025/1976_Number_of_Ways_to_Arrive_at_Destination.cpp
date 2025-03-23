#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9 + 7;
        vector<vector<pair<int,long long>>> graph(n);
        for (auto& road : roads){
            int n1 = road[0];
            int n2 = road[1];
            long long w = road[2];
            graph[n1].push_back({n2, w});
            graph[n2].push_back({n1, w});
        }
        vector<int> count(n, 0);
        vector<long long> dist(n, LLONG_MAX);
        vector<bool> comfirm(n, false);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        count[0] = 1;
        dist[0] = 0;
        pq.push({0, 0});
        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();
            if (dist[node] != d) continue;
            comfirm[node] = true;
            for (auto& [neighbor, w] : graph[node]){
                if (comfirm[neighbor] && dist[neighbor] + w == d) count[node] = (count[node] + count[neighbor]) % mod;
            }
            if (node == n-1) return count[node];
            for (auto& [neighbor, w] : graph[node]){
                if (d + w < dist[neighbor]){
                    dist[neighbor] = d + w;
                    pq.push({dist[neighbor], neighbor});
                }
            }
        }
        return count[n-1];
    }
};

int main(){
    // int n = 7;
    // vector<vector<int>> roads = {{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};
    int n = 2;
    vector<vector<int>> roads = {{1,0,10}};
    Solution S;
    cout << S.countPaths(n, roads) << endl;
    return 0;
}