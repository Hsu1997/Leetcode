#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    public:
        int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
            int n = edges.size() + 1;
            vector<vector<int>> graph(n);
            for (auto& edge : edges){
                graph[edge[0]].push_back(edge[1]);
                graph[edge[1]].push_back(edge[0]);
            }
            vector<int> path_come_from(n);
            vector<int> visited(n, 0);
            queue<int> que;
            que.push(bob);
            visited[bob] = 1;
            while(!que.empty()){
                int curr = que.front();
                que.pop();
                for (int neighbor : graph[curr]){
                    if (!visited[neighbor]){
                        visited[neighbor] = 1;
                        path_come_from[neighbor] = curr;
                        que.push(neighbor);
                    }
                }
            }
            vector<int> path;
            int curr = 0;
            while(curr != bob){
                path.push_back(curr);
                curr = path_come_from[curr];
            }
            // path.push_back(bob);
            reverse(path.begin(), path.end());
            // for (int i : path) cout << i << " ";
            // cout << endl;
            vector<int> dp(n, INT_MIN);
            dp[0] = amount[0];
            que.push(0);
            int ans = INT_MIN;
            amount[0] = 0;
            amount[bob] = 0;
            for (int bob_pos : path){
                amount[bob_pos] /= 2;
                // cout << "bob is at " << bob_pos << ", profit is " << amount[bob_pos] << " at that point" << endl;
                int curr_candidate = que.size();
                while(curr_candidate--){
                    int prev = que.front();
                    que.pop();
                    for (int neighbor : graph[prev]){
                        if (dp[neighbor] != INT_MIN) continue;
                        // cout << "now search " << neighbor << endl;
                        dp[neighbor] = dp[prev] + amount[neighbor];
                        // cout << "pos = " << neighbor << ", profit = " << dp[neighbor] << endl;
                        que.push(neighbor);
                        if (graph[neighbor].size() == 1) ans = max(ans, dp[neighbor]);
                    }
                }
                amount[bob_pos] = 0;
            }
            while(!que.empty()){
                int curr = que.front();
                que.pop();
                for (int neighbor : graph[curr]){
                    if (dp[neighbor] != INT_MIN) continue;
                    dp[neighbor] = dp[curr] + amount[neighbor];
                    amount[neighbor] = 0;
                    if (graph[neighbor].size() == 1) ans = max(ans, dp[neighbor]);
                    que.push(neighbor);
                }
            }
            return ans;
        }
    };

int main(){
    vector<vector<int>> edges = {{0,1},{1,2},{1,3},{3,4}};
    int bob = 3;
    vector<int> amount = {-2,4,2,-4,6};
    // vector<vector<int>> edges = {{0,1}};
    // int bob = 1;
    // vector<int> amount = {-7280,2350};
    // vector<vector<int>> edges = {{0,1},{1,2},{2,3}};
    // int bob = 3;
    // vector<int> amount = {-5644,-6018,1188,-8502};
    Solution S;
    cout << S.mostProfitablePath(edges, bob, amount) << endl;
    return 0;
}