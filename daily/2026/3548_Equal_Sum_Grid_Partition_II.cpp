#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m == 1 || n == 1){
            vector<int> g;
            long long t = 0;
            for (int i = 0; i < m; i++){
                for (int j = 0; j < n; j++){
                    t += grid[i][j];
                    g.push_back(grid[i][j]);
                }
            }
            n = max(n, m);
            long long l = g[0];
            long long r = t - l;
            if (l == r) return true;
            for (int i = 1; i < n - 1; i++){
                l += g[i];
                r -= g[i];
                if (l == r) return true;
                if (l - g[0] == r || l - g[i] == r || r - g[i+1] == l || r - g[n-1] == l) return true;
            }
            return false;
        }
        unordered_map<long long,int> total_cnt;
        long long total = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                total_cnt[grid[i][j]]++;
                total += grid[i][j];
            }
        }
        unordered_map<long long,int> cnt;
        long long curr = 0;
        for (int i = 0; i < m - 1; i++){
            for (int j = 0; j < n; j++){
                cnt[grid[i][j]]++;
                curr += grid[i][j];
            }
            long long remain = total - curr;
            if (curr == remain){
                // cout << "cut i = " << i << ", del nothing" << endl;
                return true;
            }
            if (curr < remain){
                long long d = remain - curr;
                if (i == m - 2){
                    if (grid[m-1][0] == d || grid[m-1][n-1] == d){
                        // cout << "cut i = " << i << ", del corner " << d << endl;
                        return true;
                    }
                }
                else{
                    if (total_cnt[d] - cnt[d] > 0){
                        // cout << "cut i = " << i << ", del " << d << endl;
                        return true;
                    }
                }
            }
            else{
                // curr > remain
                long long d = curr - remain;
                if (i == 0){
                    if (grid[0][0] == d || grid[0][n-1] == d){
                        // cout << "cut i = " << i << ", del " << d << endl;
                        return true;
                    }
                }
                else{
                    if (cnt[d] > 0){
                        // cout << "cut i = " << i << ", del " << d << endl;
                        return true;
                    }
                }
            }
        }
        cnt.clear();
        curr = 0;
        for (int j = 0; j < n - 1; j++){
            for (int i = 0; i < m; i++){
                cnt[grid[i][j]]++;
                curr += grid[i][j];
            }
            long long remain = total - curr;
            if (curr == remain){
                // cout << "cut j = " << j << ", del nothing" << endl;
                return true;
            }
            if (curr < remain){
                long long d = remain - curr;
                if (j == n - 2){
                    if (grid[0][n-1] == d || grid[m-1][n-1] == d){
                        // cout << "cut j = " << j << ", del corner " << d << endl;
                        return true;
                    }
                }
                else{
                    if (total_cnt[d] - cnt[d] > 0){
                        // cout << "cut j = " << j << ", del " << d << endl;
                        return true;
                    }
                }
            }
            else{
                // curr > remain
                long long d = curr - remain;
                if (j == 0){
                    if (grid[0][0] == d || grid[m-1][0] == d){
                        // cout << "cut j = " << j << ", del corner " << d << endl;
                        return true;
                    }
                }
                else{
                    if (cnt[d] > 0){
                        // cout << "cut j = " << j << ", del " << d << endl;
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main(){
    vector<vector<int>> grid = {{1,4},{2,3}};
    // vector<vector<int>> grid = {{1,2},{3,4}};
    // vector<vector<int>> grid = {{1,2,4},{2,3,5}};
    // vector<vector<int>> grid = {{4,1,8},{3,2,6}};
    // vector<vector<int>> grid = {{10,5,4,5}};
    Solution S;
    cout << S.canPartitionGrid(grid) << endl;
    return 0;
}