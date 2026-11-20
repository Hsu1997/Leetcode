#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int,int> dp;
        int ans = 0;
        for (int i : nums){
            dp[i + 1] = max(dp[i + 1], dp[i] + 1);
            dp[i] = max(dp[i], dp[i - 1] + 1);
            ans = max({ans, dp[i], dp[i + 1]});
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {2,1,5,1,1};
    // vector<int> nums = {1,4,7,10};
    Solution S;
    cout << S.maxSelectedElements(nums) << endl;
    return 0;
}