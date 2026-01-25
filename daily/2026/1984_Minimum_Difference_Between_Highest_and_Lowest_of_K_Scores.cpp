#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for (int i = 0; i + k - 1 < n; i++){
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {90};
    int k = 1;
    // vector<int> nums = {9,4,1,7};
    // int k = 2;
    Solution S;
    cout << S.minimumDifference(nums, k) << endl;
    return 0;
}