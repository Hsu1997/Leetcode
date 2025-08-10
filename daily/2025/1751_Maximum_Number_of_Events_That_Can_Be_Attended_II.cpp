#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        auto cmp = [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        };
        sort(events.begin(), events.end(), cmp);
        vector<int> start_time;
        for (auto& event : events) start_time.push_back(event[0]);
        vector<int> next_event(n);
        for (int i = 0; i < n; i++) next_event[i] = upper_bound(start_time.begin(), start_time.end(), events[i][1]) - start_time.begin();
        vector<vector<int>> dp(k, vector<int>(n, 0));
        dp[0][n-1] = events[n-1][2];
        int ans = dp[0][n-1];
        for (int j = n-2; j >= 0; j--){
            dp[0][j] = max(events[j][2], dp[0][j+1]);
            ans = max(ans, dp[0][j]);
        }
        for (int i = 1; i < k; i++){
            dp[i][n-1] = dp[i-1][n-1];
            for (int j = n-2; j >= 0; j--){
                int take = events[j][2] + ((next_event[j] < n)? dp[i-1][next_event[j]] : 0);
                dp[i][j] = max(take, dp[i][j+1]);
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> events = {{1,2,4},{3,4,3},{2,3,1}};
    int k = 2;
    // vector<vector<int>> events = {{1,2,4},{3,4,3},{2,3,10}};
    // int k = 2;
    // vector<vector<int>> events = {{1,1,1},{2,2,2},{3,3,3},{4,4,4}};
    // int k = 3;
    // vector<vector<int>> events = {{74,91,40}};
    // int k = 1;
    Solution S;
    cout << S.maxValue(events, k) << endl;
    return 0;
}