#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long> acc(n+1);
        acc[1] = nums[0];
        for (int i = 2; i <= n; i++) acc[i] = acc[i-1] + nums[i-1];
        // for (auto i : acc) cout << i << " ";
        // cout << endl;
        int ans = 1;
        int i = 1;
        int j = 0;
        while(i <= n){
            long diff = acc[i]-acc[j];
            long target = nums[i-1] * (i - j);
            // cout << "i = " << i << ", j = " << j << ", diff = " << diff << ", target = " << target << endl;
            if (target - diff <= k){
                ans = max(ans, i - j), i++;
            }
            else j++;
        }
        return ans;
    }
};

int main(){
    // vector<int> nums = {1,2,4};
    // int k = 5;
    // vector<int> nums = {1,4,8,13};
    // int k = 5;
    // vector<int> nums = {3,9,6};
    // int k = 2;
    vector<int> nums = {9930,9923,9983,9997,9934,9952,9945,9914,9985,9982,9970,9932,9985,9902,9975,9990,9922,9990,9994,9937,9996,9964,9943,9963,9911,9925,9935,9945,9933,9916,9930,9938,10000,9916,9911,9959,9957,9907,9913,9916,9993,9930,9975,9924,9988,9923,9910,9925,9977,9981,9927,9930,9927,9925,9923,9904,9928,9928,9986,9903,9985,9954,9938,9911,9952,9974,9926,9920,9972,9983,9973,9917,9995,9973,9977,9947,9936,9975,9954,9932,9964,9972,9935,9946,9966};
    int k = 3056;
    Solution S;
    cout << S.maxFrequency(nums, k) << endl;
    return 0;
}