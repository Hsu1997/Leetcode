#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n = b.size();
        vector<vector<long long>> dp(4, vector<long long>(n, -5e10));
        dp[0][0] = (long long)a[0] * b[0];
        for (int i = 1; i < n; i++) dp[0][i] = max(dp[0][i-1], (long long)a[0] * b[i]);
        for (int i = 1; i < 4; i++){
            for (int j = i; j < n; j++){
                dp[i][j] = max(dp[i][j-1], (long long)a[i] * b[j] + dp[i-1][j-1]); 
            }
        }
        return dp.back().back();
    }
};

int main(){
    vector<int> a = {3,2,5,6};
    vector<int> b = {2,-6,4,-5,-3,2,-7};
    // vector<int> a = {-1,4,5,-2};
    // vector<int> b = {-5,-1,-3,-2,-4};
    Solution S;
    cout << S.maxScore(a, b) << endl;
    return 0;
}