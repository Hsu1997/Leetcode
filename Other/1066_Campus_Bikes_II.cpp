#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int n, m;
    vector<int> memo;
    vector<vector<int>> workers;
    vector<vector<int>> bikes;
    int dis(int w, int b){
        return abs(workers[w][0] - bikes[b][0]) + abs(workers[w][1] - bikes[b][1]);
    }
    int dp(int mask){
        if (memo[mask] != -1) return memo[mask];
        int curr_worker = __builtin_popcount(mask);
        if (curr_worker == n) return 0;
        int best = INT_MAX;
        for (int i = 0; i < m; i++){
            if (mask & (1 << i)) continue;
            best = min(best, dis(curr_worker, i) + dp(mask | (1 << i)));
        }
        return memo[mask] = best;
    }
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        n = workers.size();
        m = bikes.size();
        this->workers = workers;
        this->bikes = bikes;
        memo = vector<int>(1 << m, -1);
        return dp(0);
    }
};

int main(){
    vector<vector<int>> workers = {{0,0},{2,1}};
    vector<vector<int>> bikes = {{1,2},{3,3}};
    // vector<vector<int>> workers = {{0,0},{1,1},{2,0}};
    // vector<vector<int>> bikes = {{1,0},{2,2},{2,1}};
    // vector<vector<int>> workers = {{0,0},{1,0},{2,0},{3,0},{4,0}};
    // vector<vector<int>> bikes = {{0,999},{1,999},{2,999},{3,999},{4,999}};
    Solution S;
    cout << S.assignBikes(workers, bikes) << endl;
    return 0;
}