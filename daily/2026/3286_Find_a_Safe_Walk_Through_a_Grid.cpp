#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        vector<vector<int>> shortestPath(m, vector<int>(n, -1));
        shortestPath[0][0] = grid[0][0];
        vector<int> dir = {0, 1, 0, -1, 0};
        auto inrange = [&](int x, int y){
            return x >= 0 && y >= 0 && x < m && y < n;
        };
        while(!pq.empty()){
            auto [p, pos] = pq.top();
            auto [i, j] = pos;
            pq.pop();
            for (int d = 0; d < 4; d++){
                int x = i + dir[d];
                int y = j + dir[d + 1];
                if (!inrange(x, y) || shortestPath[x][y] != -1) continue;
                shortestPath[x][y] = p + grid[x][y];
                pq.push({shortestPath[x][y], {x, y}});
            }
            if (shortestPath[m-1][n-1] != -1) break;
        }
        return health > shortestPath[m-1][n-1];
    }
};

int main(){
    vector<vector<int>> grid = {{0,1,0,0,0},{0,1,0,1,0},{0,0,0,1,0}};
    int health = 1;
    // vector<vector<int>> grid = {{0,1,1,0,0,0},{1,0,1,0,0,0},{0,1,1,1,0,1},{0,0,1,0,1,0}};
    // int health = 3;
    // vector<vector<int>> grid = {{1,1,1},{1,0,1},{1,1,1}};
    // int health = 5;
    Solution S;
    cout << S.findSafeWalk(grid, health) << endl;
    return 0;
}