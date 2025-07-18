#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int odd = nums[0] % 2;
        int even = !odd;
        int cross = 1;
        int prev = nums[0] % 2;
        int n = nums.size();
        for (int i = 1; i < n; i++){
            if (nums[i] % 2 == 1) odd++;
            else even++;
            if (prev ^ (nums[i] % 2)) cross++;
            prev = nums[i] % 2;
        }
        return max({odd, even, cross});
    }
};

int main(){
    vector<int> nums = {1,2,3,4};
    // vector<int> nums = {1,2,1,1,2,1,2};
    // vector<int> nums = {1,3};
    Solution S;
    cout << S.maximumLength(nums) << endl;
    return 0;
}