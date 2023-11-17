#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < n/2; i++){
            ans = max(ans, nums[i]+nums[n-1-i]);
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {3,5,2,3};
    // vector<int> nums = {3,5,4,2,4,6};
    Solution S;
    cout << S.minPairSum(nums) << endl;
    return 0;
}