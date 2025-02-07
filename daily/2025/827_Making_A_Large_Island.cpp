#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class union_set{
public:
    vector<int> parents;
    vector<int> size;
    union_set(int n){
        parents.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) parents[i] = i, size[i] = 1;
    }
    int find(int i){
        return (parents[i] == i)? i : parents[i] = find(parents[i]);
    }
    void combine_set(int i, int j){
        int roota = find(i);
        int rootb = find(j);
        if (roota == rootb) return;
        if (size[roota] < size[rootb]){
            parents[roota] = rootb;
            size[rootb] += size[roota];
        }
        else{
            parents[rootb] = roota;
            size[roota] += size[rootb];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> d = {0, 1, 0, -1, 0};
        auto in_range = [&](int i, int j){return i >= 0 && i < m && j >= 0 && j < n;};
        union_set S(m * n);
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 1){
                    for (int dir = 0; dir < 4; dir++){
                        int x = i + d[dir];
                        int y = j + d[dir+1];
                        if (!in_range(x,y) || grid[x][y] == 0) continue;
                        S.combine_set(i * n + j, x * n + y);
                    }
                }
            }
        }
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                unordered_set<int> unique_root;
                if (grid[i][j] == 0){
                    for (int dir = 0; dir < 4; dir++){
                        int x = i + d[dir];
                        int y = j + d[dir+1];
                        if (!in_range(x,y) || grid[x][y] == 0) continue;
                        int neighbor = x * n + y;
                        unique_root.insert(S.find(neighbor));
                    }
                    int curr = 1;
                    for (int r : unique_root) curr += S.size[r];
                    ans = max(ans, curr);
                }
            }
        }
        return (ans == 0)? m * n : ans;
    }
};

int main(){
    vector<vector<int>> grid = {{1,0},{0,1}};
    // vector<vector<int>> grid = {{1,1},{1,0}};
    // vector<vector<int>> grid = {{1,1},{1,1}};
    Solution S;
    cout << S.largestIsland(grid) << endl;
    return 0;
}