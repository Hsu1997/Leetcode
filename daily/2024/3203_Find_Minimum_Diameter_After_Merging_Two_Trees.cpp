#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int find_max_diameter(vector<vector<int>>& edges){
        int n = edges.size()+1;
        vector<bool> visited(n, false);
        vector<vector<int>> graph(n);
        for (auto& e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<int> dis(n, -1);
        dis[0] = 0;
        queue<int> que;
        que.push(0);
        while(!que.empty()){
            int curr = que.front();
            que.pop();
            for (int neighbor : graph[curr]){
                if (dis[neighbor] == -1){
                    dis[neighbor] = dis[curr] + 1;
                    que.push(neighbor);
                }
            }
        }
        int start = 0;
        int diameter = 0;
        for (int i = 0; i < n; i++){
            if (dis[i] > diameter){
                start = i;
                diameter = dis[i];
            }
        }
        // for (int i : dis) cout << i << " ";
        // cout << endl << "farest node " << start << " = " << diameter << endl;
        // cout << "start at node " << start << endl;

        dis = vector<int>(n, -1);
        dis[start] = 0;
        que.push(start);
        while(!que.empty()){
            int curr = que.front();
            que.pop();
            for (int neighbor : graph[curr]){
                if (dis[neighbor] == -1){
                    dis[neighbor] = dis[curr] + 1;
                    que.push(neighbor);
                }
            }
        }
        start = -1;
        diameter = 0;
        for (int i = 0; i < n; i++){
            if (dis[i] > diameter){
                start = i;
                diameter = dis[i];
            }
        }
        // for (int i : dis) cout << i << " ";
        // cout << endl << "farest node " << start << " = " << diameter << endl;
        return diameter;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2){
        int d1 = find_max_diameter(edges1);
        int d2 = find_max_diameter(edges2);
        return max({d1, d2, (d1+1)/2 + (d2+1)/2 + 1});
    }
};

int main(){
    vector<vector<int>> edges1 = {{0,1},{0,2},{0,3}};
    vector<vector<int>> edges2 = {{0,1}};
    // vector<vector<int>> edges1 = {{0,1},{0,2},{0,3},{2,4},{2,5},{3,6},{2,7}};
    // vector<vector<int>> edges2 = {{0,1},{0,2},{0,3},{2,4},{2,5},{3,6},{2,7}};
    // vector<vector<int>> edges1 = {};
    // vector<vector<int>> edges2 = {};
    // vector<vector<int>> edges1 = {{0,1},{2,0},{3,2},{3,6},{8,7},{4,8},{5,4},{3,5},{3,9}};
    // vector<vector<int>> edges2 = {{0,1},{0,2},{0,3}};
    Solution S;
    cout << S.minimumDiameterAfterMerge(edges1, edges2) << endl;
    return 0;
}