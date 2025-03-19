#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool has_subarray(vector<vector<int>>& acc_count, int length){
        int n = acc_count.size();
        for (int k = length - 1; k < n; k++){
            bool all_at_most_one_exist = true;
            for (int d = 0; d < 32; d++){
                if (acc_count[k][d] - ((k - length >= 0)? acc_count[k-length][d] : 0) > 1){
                    all_at_most_one_exist = false;
                    break;
                }
            }
            if (all_at_most_one_exist) return true;
        }
        return false;
    }
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> acc_count(n, vector<int>(32, 0));
        for (int i = 0; i < n; i++){
            int curr = nums[i];
            for (int d = 0; d < 32; d++){
                if (i > 0) acc_count[i][d] = acc_count[i-1][d];
                if (curr % 2 == 1) acc_count[i][d]++;
                curr /= 2;
            }
        }
        int left = 1;
        int right = n;
        int ans = 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if (has_subarray(acc_count, mid)){
                left = mid + 1;
                ans = max(ans, mid);
            }
            else right = mid - 1;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,3,8,48,10};
    // vector<int> nums = {3,1,5,11,13};
    Solution S;
    cout << S.longestNiceSubarray(nums) << endl;
    return 0;
}