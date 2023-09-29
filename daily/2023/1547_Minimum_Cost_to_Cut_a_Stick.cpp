#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> c;
    vector<vector<int>> dp;

    int helper(int s, int e){
        if (s >= e) return 0;
        if (s == e - 1) return 0;
        if (dp[s][e] != -1) return dp[s][e];
        int temp = INT_MAX;
        for (int i = s+1; i < e; i++){
            temp = min(temp, helper(s, i) + helper(i, e));
        }
        dp[s][e] = c[e] - c[s] + temp;
        return dp[s][e];
    }

    int minCost(int n, vector<int>& cuts) {
        c = cuts;
        sort(c.begin(), c.end());
        if (c[0] != 0) c.insert(c.begin(), 0);
        if (c.back() != n) c.push_back(n);
        int segment = c.size();
        dp = vector<vector<int>>(segment, vector<int>(segment, -1));
        helper(0, segment - 1);
        // for (auto i : dp){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }
        return dp[0][segment-1];
    }
};

int main(){
    // int n = 7;
    // vector<int> cuts = {1,3,4,5};
    // int n = 9;
    // vector<int> cuts = {5,6,1,4,2};
    // int n = 100;
    // vector<int> cuts = {49};
    // int n = 10;
    // vector<int> cuts = {7,8,9,2,1};
    int n = 36;
    vector<int> cuts = {13,17,15,18,3,22,27,6,35,7,11,28,26,20,4,5,21,10,8};
    Solution S;
    cout << S.minCost(n, cuts) << endl;
    return 0;
}