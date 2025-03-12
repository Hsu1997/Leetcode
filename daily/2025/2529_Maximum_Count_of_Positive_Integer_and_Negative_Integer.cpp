#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        if (nums[0] > 0 || nums[n-1] < 0) return n;
        int pos = n - (upper_bound(nums.begin(), nums.end(), 0) - nums.begin());
        int neg = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        // cout << pos << " ," << neg << endl;
        return max(pos, neg);
    }
};

int main(){
    vector<int> nums = {-2,-1,-1,1,2,3};
    // vector<int> nums = {-3,-2,-1,0,0,1,2};
    // vector<int> nums = {5,20,66,1314};
    Solution S;
    cout << S.maximumCount(nums) << endl;
    return 0;
}