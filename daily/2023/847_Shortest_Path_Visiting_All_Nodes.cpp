#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n < 2) return 0;
        int ending_status = (1 << n) - 1;
        queue<pair<int,int>> que;
        vector<vector<bool>> s(n, vector<bool>((1 << n), false));
        for (int i = 0; i < n; i++){
            s[i][1 << i] = true;
            que.push({i, (1 << i)});
        }
        int period = 0;
        while(!que.empty()){
            int c = que.size();
            while(c--){
                int node = que.front().first;
                int status = que.front().second;
                que.pop();
                if (status == ending_status) return period;
                for (auto neighbor : graph[node]){
                    int new_status = status | (1 << neighbor);
                    if (!s[neighbor][status]){
                        s[neighbor][status] = true;
                        que.push({neighbor, new_status});
                    }
                }
            }
            period++;
        }
        return -1;
    }
};

int main(){
    vector<vector<int>> graph = {{1,2,3},{0},{0},{0}};
    // vector<vector<int>> graph = {{1},{0,2,4},{1,3,4},{2},{1,2}};
    Solution S;
    cout << S.shortestPathLength(graph) << endl;
    return 0;
}