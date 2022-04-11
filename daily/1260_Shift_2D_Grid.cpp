#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector< vector<int> > ans;
        int n = grid.size();
        int m = grid[0].size();
        k %= n * m;
        for (int i = 0; i < n * m / 2; i++) swap(grid[i/m][i%m], grid[(n*m-1-i)/m][(n*m-1-i)%m]);
        for (int i = 0; i < k / 2; i++) swap(grid[i/m][i%m], grid[(k-1-i)/m][(k-1-i)%m]);
        for (int i = k; i < k + (n * m - k) / 2; i++) swap(grid[i/m][i%m], grid[(n*m-1+k-i)/m][(n*m-1+k-i)%m]);
        return grid;
    }
};

int main(){
    // vector< vector<int> > grid = {{1,2,3},{4,5,6},{7,8,9}};
    vector< vector<int> > grid = {{3,8,1,9},{19,7,2,5},{4,6,11,10},{12,0,21,13}};
    int k = 4;
    Solution S;
    vector< vector<int> > ans = S.shiftGrid(grid, k);
    for (auto i : ans){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}