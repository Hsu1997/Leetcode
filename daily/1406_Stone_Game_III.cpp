#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int helper(vector<int>& stoneValue, int p, int s){
        if (s == n) return 0;
        if (dp[p][s] != -50000002) return dp[p][s];
        int res;
        if (p == 0){
            res = -50000001;
            int acc = 0;
            for (int i = 0; i < 3; i++){
                if (s+i < n){
                    acc += stoneValue[s+i];
                    res = max(res, acc + helper(stoneValue, 1, s+i+1));
                }
            }
        }
        else{
            res = 50000001;
            for (int i = 0; i < 3; i++){
                if (s+i < n) res = min(res, helper(stoneValue, 0, s+i+1));
            }
        }
        dp[p][s] = res;
        return dp[p][s];
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        dp = vector<vector<int>>(2, vector<int>(n+1, -50000002));
        int total = 0;
        for (auto i : stoneValue) total += i;

        helper(stoneValue, 0, 0);
        int Alice = dp[0][0];
        int Bob = total - Alice;
        if (Alice == Bob) return "Tie";
        else return (Alice > Bob)? "Alice" : "Bob";
        return "error";
    }
};

int main(){
    // vector<int> stoneValue = {1,2,3,7};
    vector<int> stoneValue = {1,2,3,-9};
    // vector<int> stoneValue = {1,2,3,6};
    Solution S;
    cout << S.stoneGameIII(stoneValue) << endl;
    return 0;
}