#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
public:
    vector<int> parents;

    UnionFind(int n){
        // (n), (n + 1) is top and bottom
        parents.resize(n + 2);
        for (int i = 0; i < n + 2; i++) parents[i] = i;
    }

    int find(int i){
        return (parents[i] == i)? parents[i] : parents[i] = find(parents[i]);
    }

    void combine(int i, int j){
        int x = find(i);
        int y = find(j);
        parents[y] = x;
    }
};

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = row * col;
        UnionFind land(n);
        vector<vector<int>> l(row, vector<int>(col, 0));

        auto index = [&](int x, int y){
            return (x - 1) * col + (y - 1);
        };
        auto valid = [&](int x, int y){
            return x >= 1 && x <= row && y >= 1 && y <= col;
        };
        vector<int> d = {0, 1, 0, -1, 0};

        for (int i = n - 1; i >= 0; i--){
            int r = cells[i][0];
            int c = cells[i][1];
            int idx = index(r, c);
            l[r-1][c-1] = 1;
            for (int dir = 0; dir < 4; dir++){
                int nr = r + d[dir];
                int nc = c + d[dir+1];
                if (valid(nr, nc) && l[nr - 1][nc - 1] == 1){
                    int neighborIdx = index(nr, nc);
                    int x = land.find(neighborIdx);
                    land.combine(idx, x);
                }
            }
            if (r == 1) land.combine(idx, n);
            if (r == row) land.combine(idx, n + 1);
            if (land.find(n) == land.find(n + 1)) return i;
        }
        return -1;
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