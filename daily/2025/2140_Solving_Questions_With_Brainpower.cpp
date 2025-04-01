#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, 0);
        dp[n-1] = questions[n-1][0];
        for (int i = n-2; i >= 0; i--){
            dp[i] = questions[i][0];
            if (i + questions[i][1] + 1 < n) dp[i] += dp[i+questions[i][1] + 1];
            dp[i] = max(dp[i], dp[i+1]);
        }
        return dp[0];
    }
};

int main(){
    vector<vector<int>> questions = {{3,2},{4,3},{4,4},{2,5}};
    // vector<vector<int>> questions = {{1,1},{2,2},{3,3},{4,4},{5,5}};
    Solution S;
    cout << S.mostPoints(questions) << endl;
    return 0;
}