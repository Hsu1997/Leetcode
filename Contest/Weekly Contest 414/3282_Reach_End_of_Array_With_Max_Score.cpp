#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int temp_max = nums[0];
        for (int i = 1; i < n; i++){
            ans += temp_max;
            temp_max = max(temp_max, nums[i]);
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,3,1,5};
    // vector<int> nums = {4,3,1,3,2};
    Solution S;
    cout << S.findMaximumScore(nums) << endl;
    return 0;
}