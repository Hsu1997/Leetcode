#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool dijkstra(vector<vector<pair<int, int>>>& graph, vector<bool>& online, long long k, long long score){
        int n = online.size();
        vector<long long> dis(n, LLONG_MAX);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0, 0});
        dis[0] = 0;
        while(!pq.empty()){
            auto [d, idx] = pq.top();
            pq.pop();
            if (!online[idx] || dis[idx] < d) continue;
            if (d > k) return false;
            if (idx == n - 1) return true;
            for (auto [e, r] : graph[idx]){
                if (!online[e] || r < score) continue;
                if (d + r < dis[e] && d + r <= k){
                    dis[e] = d + r;
                    pq.push({d + r, e});
                }
            }
        }
        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> graph(n);
        long long maxPath = 0;
        for (vector<int>& edge : edges){
            int s = edge[0];
            int e = edge[1];
            int r = edge[2];
            maxPath = max(maxPath, 1LL * r);
            graph[s].push_back({e, r});
        }
        long long l = 0;
        long long r = maxPath;
        long long ans = -1;
        while(l <= r){
            long long mid = l + (r - l) / 2;
            if (dijkstra(graph, online, k, mid)){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> edges = {{0,1,5},{1,3,10},{0,2,3},{2,3,4}};
    vector<bool> online = {true,true,true,true};
    long long k = 10;
    // vector<vector<int>> edges = {{0,1,7},{1,4,5},{0,2,6},{2,3,6},{3,4,2},{2,4,6}};
    // vector<bool> online = {true,true,true,false,true};
    // long long k = 12;
    Solution S;
    cout << S.findMaxPathScore(edges, online, k) << endl;
    return 0;
}