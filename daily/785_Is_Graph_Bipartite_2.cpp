#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> g(n,0);
        queue<int> que;
        for (int i = 0; i < n; i++){
            if (graph[i].empty() || g[i] != 0) continue;
            else{
                g[i] = 1;
                que.push(i);
                while(!que.empty()){
                    int now = que.front();
                    que.pop();
                    for (auto neighbor : graph[now]){
                        if (g[neighbor] == g[now]) return false;
                        if (g[neighbor] == 0){
                            que.push(neighbor);
                            g[neighbor] = -g[now];
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main(){
    // vector<vector<int>> graph = {{1,2,3},{0,2},{0,1,3},{0,2}};
    vector<vector<int>> graph = {{1,3},{0,2},{1,3},{0,2}};
    // vector<vector<int>> graph = {{},{2,4,6},{1,4,8,9},{7,8},{1,2,8,9},{6,9},{1,5,7,8,9},{3,6,9},{2,3,4,6,9},{2,4,5,6,7,8}};
    Solution S;
    cout << S.isBipartite(graph) << endl;
    return 0;
}