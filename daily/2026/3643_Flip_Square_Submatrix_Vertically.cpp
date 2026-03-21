#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int col = y; col < y + k; col++){
            int row = x;
            int vrow = x + k - 1;
            while(row < vrow){
                swap(grid[row][col], grid[vrow][col]);
                row++, vrow--;
            }
        }
        return grid;
    }
};

int main(){
    vector<vector<int>> grid = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int x = 1;
    int y = 0;
    int k = 3;
    // vector<vector<int>> grid = {{3,4,2,3},{2,3,4,2}};
    // int x = 0;
    // int y = 2;
    // int k = 2;
    Solution S;
    vector<vector<int>> ans = S.reverseSubmatrix(grid, x, y, k);
    for (auto r : ans){
        for (auto c : r) cout << c << " ";
        cout << endl;
    }
    return 0;
}