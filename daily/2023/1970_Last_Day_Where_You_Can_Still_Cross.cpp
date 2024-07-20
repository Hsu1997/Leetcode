#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> d = {0, 1, 0, -1, 0};
    int r, c;
    bool in_range(int x, int y){
        return (x >= 0 && y >= 0 && x < r && y < c);
    }
    bool crossable(vector<vector<bool>>& land){
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        queue<pair<int,int>> que;
        for (int j = 0; j < c; j++) if (!visited[0][j] && land[0][j]) visited[0][j] = true, que.push({0,j});
        while(!que.empty()){
            pair<int,int> temp = que.front();
            que.pop();
            if (temp.first == r - 1) return true;
            for (int k = 0; k < 4; k++){
                int x = temp.first + d[k];
                int y = temp.second + d[k+1];
                if (in_range(x, y) && !visited[x][y] && land[x][y]) visited[x][y] = true, que.push({x,y});
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        if (cells.size() < col) return cells.size();
        r = row;
        c = col;
        vector<vector<bool>> land(r, vector<bool>(c, true));
        land[cells[0][0]-1][cells[0][1]-1] = false;
        int left = 0;
        int right = cells.size() - 1;
        int prev = -1;
        int ans = 0;
        while(left <= right){
            int mid = left + (right - left) / 2;
            // cout << "left = " << left << ", right = " << right << ", checking " << mid << endl;
            for (int i = prev + 1; i <= mid; i++){
                land[cells[i][0]-1][cells[i][1]-1] = false;
            }
            for (int i = prev; i > mid; i--){
                land[cells[i][0]-1][cells[i][1]-1] = true;
            }
            prev = mid;
            if (crossable(land)) left = mid + 1, ans = mid;
            else right = mid - 1;
        }
        return ans + 1;
    }
};

int main(){
    int row = 2;
    int col = 2;
    vector<vector<int>> cells = {{1,1},{2,1},{1,2},{2,2}};
    // int row = 2;
    // int col = 2;
    // vector<vector<int>> cells = {{1,1},{1,2},{2,1},{2,2}};
    // int row = 3;
    // int col = 3;
    // vector<vector<int>> cells = {{1,2},{2,1},{3,3},{2,2},{1,1},{1,3},{2,3},{3,2},{3,1}};
    Solution S;
    cout << S.latestDayToCross(row, col, cells) << endl;
    return 0;
}