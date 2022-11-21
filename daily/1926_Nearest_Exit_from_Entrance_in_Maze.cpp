#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int m;
    int n;
    vector<int> dir_x = {-1,0,1,0};
    vector<int> dir_y = {0,1,0,-1};

    bool in_board(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        m = maze.size();
        n = maze[0].size();
        queue<vector<int>> candidate;
        candidate.push(entrance);
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (maze[i][j] == '+') visited[i][j] = true;
            }
        }
        visited[entrance[0]][entrance[1]] = true;
        int step = 0;
        while(!candidate.empty()){
            step++;
            int num = candidate.size();
            for(int k = 0; k < num; k++){
                vector<int> p = candidate.front();
                int x = p[0];
                int y = p[1];
                candidate.pop();
                for(int dir = 0; dir < 4; dir++){
                    if (in_board(x + dir_x[dir], y + dir_y[dir]) && !visited[x + dir_x[dir]][y + dir_y[dir]]){
                        if (x + dir_x[dir] == 0 || x + dir_x[dir] == m-1 || y + dir_y[dir] == 0 || y + dir_y[dir] == n-1) return step;
                        candidate.push({x + dir_x[dir], y + dir_y[dir]});
                        visited[x + dir_x[dir]][y + dir_y[dir]] = true;
                    }
                }
            }
        }
        return -1;
    }
};

int main(){
    vector<vector<char>> maze = {{'+','+','.','+'},{'.','.','.','+'},{'+','+','+','.'}};
    vector<int> entrance = {1,2};
    // vector<vector<char>> maze = {{'+','+','+'},{'.','.','.'},{'+','+','+'}};
    // vector<int> entrance = {1,0};
    // vector<vector<char>> maze = {{'.','+'}};
    // vector<int> entrance = {0,0};

    Solution S;
    cout << S.nearestExit(maze, entrance) << endl;
    return 0;
}