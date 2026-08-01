#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int dp(vector<int>& nums, vector<vector<int>>& memo, int s, int e, int p){
        if (s > e) return 0;
        if (memo[s][e] != INT_MIN) return memo[s][e];
        if (p == 0){
            memo[s][e] = max(nums[s] + dp(nums, memo, s + 1, e, 1), nums[e] + dp(nums, memo, s, e - 1, 1));
        }
        else{
            memo[s][e] = min(-nums[s] + dp(nums, memo, s + 1, e, 0), -nums[e] + dp(nums, memo, s, e - 1, 0));
        }
        return memo[s][e];
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n, INT_MIN));
        dp(nums, memo, 0, n - 1, 0);
        return memo[0][n-1] >= 0;
    }
};

int main(){
    vector<int> nums = {1,5,2};
    // vector<int> nums = {1,5,233,7};
    Solution S;
    cout << S.predictTheWinner(nums) << endl;
    return 0;
}