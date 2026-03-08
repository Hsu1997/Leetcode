#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        if (nums[1] <= nums[0]) return false;
        int n = nums.size();
        int t = 0;
        for (int i = 1; i + 1 < n; i++){
            int prev = nums[i] - nums[i-1];
            int next = nums[i+1] - nums[i];
            if (prev * next == 0) return false;
            else if (prev * next < 0) t++;
            else continue;
        }
        return t == 2;
    }
};

int main(){
    vector<int> nums = {1,3,5,4,2,6};
    // vector<int> nums = {2,1,3};
    // vector<int> nums = {9,2,9,1};
    Solution S;
    cout << S.isTrionic(nums) << endl;
    return 0;
}