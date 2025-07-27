#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int m = 1;
        int r = 2;
        int ans = 0;
        while(m < n - 1){
            while(r < n && nums[r] == nums[m]) r++;
            if (r == n) break;
            if ((nums[l] < nums[m] && nums[r] < nums[m]) || (nums[l] > nums[m] && nums[r] > nums[m])) ans++;
            l = m;
            m = r;
            r++;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {2,4,1,1,6,5};
    // vector<int> nums = {6,6,5,5,4,1};
    Solution S;
    cout << S.countHillValley(nums) << endl;
    return 0;
}