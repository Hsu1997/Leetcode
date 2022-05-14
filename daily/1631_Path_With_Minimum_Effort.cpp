#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int n;
    int m;
    vector<vector<pair<int, int>>> adj;

    bool dfs(vector<bool> &visited, int node, int limit){
        visited[node] = true;
        if (node == n*m-1) return true;
        for (auto edge : adj[node]){
            if (!visited[edge.first] && edge.second <= limit && dfs(visited, edge.first, limit)) return true;
        }
        return false;
    }

    bool verify(int limit){
        vector<bool> visited(n*m-1, 0);
        dfs(visited, 0, limit);
        // for (auto i : visited) cout << i << " ";
        // cout << endl;
        return visited[n*m-1];
    }

    bool in_graph(int x, int y){
        return (x >= 0 && x < n && y >= 0 && y < m);
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        if (n*m == 1) return 0;
        adj.resize(n * m);
        int max_distance = 0;

        vector<int> x_direction = {-1,0,1,0};
        vector<int> y_direction = {0,1,0,-1};

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                max_distance = max(max_distance, heights[i][j]);
                for (int k = 0; k < 4; k++){
                    int new_x = i + x_direction[k];
                    int new_y = j + y_direction[k];
                    if (in_graph(new_x, new_y)){
                        adj[i*m+j].push_back({new_x * m + new_y, abs(heights[new_x][new_y]-heights[i][j])});
                    }
                }
            }
        }

        // for (int i = 0; i < adj.size(); i++){
        //     cout << i << " : ";
        //     for (auto j : adj[i]){
        //         cout << j.first << "," << j.second << " ";
        //     }
        //     cout << endl;
        // }

        int low = 0;
        int high = max_distance;
        while(low < high){
            int mid = low + (high - low)/2;
            // cout << mid << " : ";
            if (verify(mid)) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};

int main(){
    vector<vector<int>> heights = {{1,2,2},{3,8,2},{5,3,5}};
    // vector<vector<int>> heights = {{1,2,3},{3,8,4},{5,3,5}};
    Solution S;
    cout << S.minimumEffortPath(heights) << endl;
    return 0;
}