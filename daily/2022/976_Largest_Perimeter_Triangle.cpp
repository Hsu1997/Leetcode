#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        for (int i = nums.size()-1; i >= 2; i--){
            if (nums[i] < nums[i-1] + nums[i-2]) return nums[i] + nums[i-1] + nums[i-2];
        }
        return 0;
    }
};

int main(){
    // vector<int> nums = {2,1,2};
    // vector<int> nums = {1,2,1};
    vector<int> nums = {3,6,2,3};
    Solution S;
    cout << S.largestPerimeter(nums) << endl;
    return 0;
}