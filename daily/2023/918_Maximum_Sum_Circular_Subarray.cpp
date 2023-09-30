#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int ans = nums[0];

        int acc_min = min(0,nums[0]);
        int acc_max = nums[0];
        vector<int> acc(n, 0);
        acc[0] = nums[0];
        for (int i = 1; i < n; i++){
            ans = max(ans, nums[i]);
            acc[i] = acc[i-1] + nums[i];
            ans = max(ans, acc[i] - acc_min);
            acc_min = min(acc_min, acc[i]);
        }

        vector<int> acc_rev(n, 0);
        acc_rev[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i--){
            acc_rev[i] = acc_rev[i+1] + nums[i];
        }
        for (int i = 0; i < n-1; i++){
            acc_max = max(acc_max, acc[i]);
            ans = max(ans, acc_rev[i+1] + acc_max);
        }

        return ans;
    }
};

int main(){
    // vector<int> nums = {1,-2,3,-2};
    vector<int> nums = {-5,3,5};
    Solution S;
    cout << S.maxSubarraySumCircular(nums) << endl;
    return 0;
}