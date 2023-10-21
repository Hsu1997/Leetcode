#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        dp[0] = nums[0];
        // int prev = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> pq;
        pq.push({nums[0], 0});
        int ans = nums[0];
        for (int i = 1; i < n; i++){
            while(pq.size() > 1 && i - pq.top().second > k) pq.pop();
            dp[i] = max(nums[i], nums[i] + pq.top().first);
            pq.push({dp[i],i});
            ans = max(ans, dp[i]);
        }
        // for (auto i : dp) cout << i << " ";
        // cout << endl;
        return ans;
    }
};

int main(){
    vector<int> nums = {10,2,-10,5,20};
    int k = 2;
    // vector<int> nums = {-1,-2,-3};
    // int k = 1;
    // vector<int> nums = {10,-2,-10,-5,20};
    // int k = 2;
    Solution S;
    cout << S.constrainedSubsetSum(nums, k) << endl;
    return 0;
}