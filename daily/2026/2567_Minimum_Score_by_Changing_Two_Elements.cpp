#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return 0;
        sort(nums.begin(), nums.end());
        return min({nums[n-1] - nums[2], nums[n-2] - nums[1], nums[n-3] - nums[0]});
    }
};

int main(){
    vector<int> nums = {1,4,7,8,5};
    // vector<int> nums = {1,4,3};
    Solution S;
    cout << S.minimizeSum(nums) << endl;
    return 0;
}