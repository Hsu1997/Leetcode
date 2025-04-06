#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        for (int i = 1; i < n; i++){
            for (int j = 0; j < i; j++){
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }
        int max_len = 1;
        int max_index = 0;
        for (int i = 0; i < n; i++){
            if (dp[i] > max_len) max_len = dp[i], max_index = i;
        }
        vector<int> ans;
        while(max_index != -1){
            ans.push_back(nums[max_index]);
            max_index = prev[max_index];
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,3};
    // vector<int> nums = {1,2,4,8};
    Solution S;
    vector<int> ans = S.largestDivisibleSubset(nums);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}