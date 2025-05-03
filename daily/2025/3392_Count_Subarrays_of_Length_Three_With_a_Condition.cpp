#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 1; i < n-1; i++){
            if ((nums[i-1] + nums[i+1]) * 2 == nums[i]) ans++;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,1,4,1};
    // vector<int> nums = {1,1,1};
    Solution S;
    cout << S.countSubarrays(nums) << endl;
    return 0;
}