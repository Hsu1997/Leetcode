#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<int> dp(n+1, 0);
        for (int i = 0; i < n; i++){
            int point = questions[i][0];
            int cost = questions[i][1];
            dp[min(i+cost+1, n)] = max(dp[min(i+cost+1, n)], dp[i] + point);
            dp[i+1] = max(dp[i+1], dp[i]);
            // cout << dp[i] << " ";
        }
        // cout << dp[n] << endl;
        return dp[n];
    }
};

int main(){
    // vector<vector<int>> questions = {{3,2},{4,3},{4,4},{2,5}};
    vector<vector<int>> questions = {{1,1},{2,2},{3,3},{4,4},{5,5}};
    Solution S;
    cout << S.mostPoints(questions) << endl;
    return 0;
}