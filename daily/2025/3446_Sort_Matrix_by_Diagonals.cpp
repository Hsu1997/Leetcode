#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int r = 0; r < n; r++){
            vector<int> temp = {};
            int i = r;
            int j = 0;
            while(i < n) temp.push_back(grid[i++][j++]);
            sort(temp.begin(), temp.end(), greater<int>());
            i = r;
            j = 0;
            while(i < n) grid[i++][j++] = temp[j];
        }
        for (int c = 1; c < n; c++){
            vector<int> temp = {};
            int i = 0;
            int j = c;
            while(j < n) temp.push_back(grid[i++][j++]);
            sort(temp.begin(), temp.end());
            i = 0;
            j = c;
            while(j < n) grid[i++][j++] = temp[i];
        }
        return grid;
    }
};

int main(){
    vector<vector<int>> grid = {{1,7,3},{9,8,2},{4,5,6}};
    // vector<vector<int>> grid = {{0,1},{1,2}};
    // vector<vector<int>> grid = {{1}};
    Solution S;
    S.sortMatrix(grid);
    for (auto row : grid){
        for (auto element : row){
            cout << element << " ";
        }
        cout << endl;
    }
    return 0;
}