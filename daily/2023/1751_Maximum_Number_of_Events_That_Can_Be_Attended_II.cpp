#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int binary_search(vector<vector<int>>& events, int row, int start_index, int start_time){
        if (start_index == n || events.back()[0] < start_time) return 0;
        int left = start_index;
        int right = n-1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if (events[mid][0] < start_time) left = mid + 1;
            else right = mid;
        }
        return dp[row][right];
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        n = events.size();
        dp = vector<vector<int>>(k+1, vector<int>(n, -1));
        for (int j = 0; j < n; j++) dp[0][j] = 0;
        for (int i = 1; i <= k; i++){
            dp[i][n-1] = events[n-1][2];
            for (int j = n-2; j >= 0; j--){
                dp[i][j] = max(dp[i][j+1], events[j][2] + binary_search(events, i-1, j+1, events[j][1]+1));
            }
        }
        return dp[k][0];
    }
};

int main(){
    vector<vector<int>> events = {{1,2,4},{3,4,3},{2,3,1}};
    int k = 2;
    // vector<vector<int>> events = {{1,2,4},{3,4,3},{2,3,10}};
    // int k = 2;
    // vector<vector<int>> events = {{1,1,1},{2,2,2},{3,3,3},{4,4,4}};
    // int k = 3;
    Solution S;
    cout << S.maxValue(events, k) << endl;
    return 0;
}