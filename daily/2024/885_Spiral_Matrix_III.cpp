#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool in_range(int row, int col) {return row >= 0 && col >= 0 && row < rows && col < cols;}

    vector<vector<int>> spiralMatrixIII(int _rows, int _cols, int rStart, int cStart) {
        rows = _rows;
        cols = _cols;
        int dir = 0;
        int path = 1;
        int path_count = 0;
        int x = rStart;
        int y = cStart;
        ans.push_back({x, y});

        while(ans.size() < rows * cols){
            x += xd[dir];
            y += yd[dir];
            if (in_range(x, y)) ans.push_back({x, y});
            path_count++;
            if (path_count == path){
                path_count = 0;
                if (dir % 2) path++;
                dir = (dir + 1) % 4;
            }
        }
        return ans;
    }
private:
    int rows;
    int cols;
    vector<vector<int>> ans;
    int count = 0;
    vector<int> xd = {0, 1, 0, -1};
    vector<int> yd = {1, 0, -1, 0};
};

int main(){
    int rows = 1;
    int cols = 4;
    int rStart = 0;
    int cStart = 0;
    // int rows = 5;
    // int cols = 6;
    // int rStart = 1;
    // int cStart = 4;
    Solution S;
    vector<vector<int>> ans = S.spiralMatrixIII(rows, cols, rStart, cStart);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}