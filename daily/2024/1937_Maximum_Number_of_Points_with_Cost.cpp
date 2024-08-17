#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<long long> dp(n);
        vector<long long> pre_dp(n);
        for (int j = 0; j < n; j++) pre_dp[j] = points[0][j];
        for (int i = 1; i < m; i++){
            long long temp_max = -1;
            for (int j = 0; j < n; j++){
                temp_max--;
                temp_max = max(temp_max, pre_dp[j]);
                dp[j] = temp_max + points[i][j];
            }
            temp_max = -1;
            for (int j = n - 1; j >= 0; j--){
                temp_max--;
                temp_max = max(temp_max, pre_dp[j]);
                dp[j] = max(dp[j], temp_max + points[i][j]);
            }
            swap(dp, pre_dp);
        }
        long long ans = 0;
        for (long long i : pre_dp) ans = max(ans, i);
        return ans;
    }
};

int main(){
    vector<vector<int>> points = {{1,2,3},{1,5,1},{3,1,1}};
    // vector<vector<int>> points = {{1,5},{2,3},{4,2}};
    Solution S;
    cout << S.maxPoints(points) << endl;
    return 0;
}