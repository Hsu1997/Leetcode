#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        int M = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        int MOD = 1e9+7;
        // vector<vector<int>> dp(n, vector<int>(M + 1, 0));
        vector<int> acc(M + 1, 0);
        vector<int> temp_acc(M + 1, 0);
        int count = 0;
        for (int j = 0; j <= M; j++){
            if (j <= nums[0]) acc[j] = j + 1;
        }
        for (int i = 1; i < n; i++){
            count = 0;
            int dp;
            for (int j = 0; j <= M; j++){
                if (j > nums[i]) dp = 0;
                else{
                    int index = min({j, nums[i-1] - (nums[i] - j), M});
                    if (index < 0) dp = 0;
                    else dp = acc[index];
                }
                count = (count + dp) % MOD;
                temp_acc[j] = count;
            }
            swap(acc, temp_acc);
        }
        return acc.back();
    }
};

int main(){
    vector<int> nums = {2,3,2};
    // vector<int> nums = {5,5,5,5};
    Solution S;
    cout << S.countOfPairs(nums) << endl;
    return 0;
}