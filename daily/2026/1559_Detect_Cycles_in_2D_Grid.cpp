#include <iostream>
#include <vector>

using namespace std;

class DSU {
public:
    vector<int> parents;
    DSU(int n){
        parents.resize(n);
        for (int i = 0; i < n; i++) parents[i] = i;
    }
    int find(int i){
        return parents[i] == i? i : parents[i] = find(parents[i]);
    }
    void combine(int i, int j){
        int x = find(i);
        int y = find(j);
        parents[y] = x;
    }
};

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        DSU u(m * n);
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                // down
                if (i + 1 < m && grid[i][j] == grid[i+1][j]){
                    u.combine(i * n + j, (i + 1) * n + j);
                }
                // right
                if (j + 1 < n && grid[i][j] == grid[i][j+1]){
                    if (u.find(i * n + j) == u.find(i * n + j + 1)) return true;
                    u.combine(i * n + j, i * n + j + 1);
                }
            }
        }
        return false;
    }
};

int main(){
    vector<vector<char>> grid = {{'a','a','a','a'},{'a','b','b','a'},{'a','b','b','a'},{'a','a','a','a'}};
    // vector<vector<char>> grid = {{'c','c','c','a'},{'c','d','c','c'},{'c','c','e','c'},{'f','c','c','c'}};
    // vector<vector<char>> grid = {{'a','b','b'},{'b','z','b'},{'b','b','a'}};
    Solution S;
    cout << S.containsCycle(grid) << endl;
    return 0;
}