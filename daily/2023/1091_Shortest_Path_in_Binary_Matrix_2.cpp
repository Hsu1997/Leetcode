#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int n;
    vector<int> x = {-1,-1,0,1,1,1,0,-1};
    vector<int> y = {0,1,1,1,0,-1,-1,-1};

    bool in_grid(int x, int y){
        return (x >= 0 && x < n && y >= 0 && y < n);
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();
        queue<pair<int,int>> que;
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        que.push({0,0});
        grid[0][0] = 1;

        int round = 0;
        while(!que.empty()){
            round++;
            int s = que.size();
            while(s--){
                pair<int,int> temp = que.front();
                if (temp.first == n-1 && temp.second == n-1) return round;
                que.pop();
                for (int d = 0; d < 8; d++){
                    int nx = temp.first + x[d];
                    int ny = temp.second + y[d];
                    if (in_grid(nx,ny) && grid[nx][ny] == 0){
                        que.push(make_pair(nx,ny));
                        grid[nx][ny] = 1;
                    }
                }
            }
        }
        return -1;
    }
};

int main(){
    // vector<vector<int>> grid = {{0,1},{1,0}};
    vector<vector<int>> grid = {{0,0,0},{1,1,0},{1,1,0}};
    Solution S;
    cout << S.shortestPathBinaryMatrix(grid) << endl;
    return 0;
}