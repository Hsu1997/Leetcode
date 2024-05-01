#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int n, m;
    vector<int> distance;

    int position(int row, int col){
        if (row < 0 || row >= n || col < 0 || col >= n) return -1;
        return row * n + col;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        if (grid[0][0] == 1) return -1;

        distance = vector<int>(n*m, numeric_limits<int>::max());
        distance[0] = 1;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> current_node;
        // {distance, node}
        current_node.push({0,1});

        vector<int> x_offset = {-1,-1,0,1,1,1,0,-1};
        vector<int> y_offset = {0,1,1,1,0,-1,-1,-1};

        while(!current_node.empty()){
            int node = current_node.top().first;
            int dis = current_node.top().second;
            current_node.pop();
            int current_x = node / n;
            int current_y = node % n;

            for (int i = 0; i < 8; i++){
                int now_position = position(current_x + x_offset[i], current_y + y_offset[i]);
                if (now_position >= 0 && grid[current_x + x_offset[i]][current_y + y_offset[i]] == 0 && dis+1 < distance[now_position]){
                    if (now_position == n*m-1) return dis+1;
                    distance[now_position] = dis + 1;
                    current_node.push({now_position, dis+1});
                }
            }
        }
        return (distance[n*m-1] == numeric_limits<int>::max())? -1:distance[n*m-1];
    }
};

int main(){
    vector<vector<int>> grid = {{0,0,0},{1,1,0},{1,1,0}};
    Solution S;
    cout << S.shortestPathBinaryMatrix(grid) << endl;
    // for (auto i : S.distance) cout << i << " ";
    // cout << endl;
    return 0;
}