#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // for (auto i : nums) cout << i << " ";
        int i = 0, j = nums.size()-1;
        while(i < j){
            if (-nums[i] == nums[j]) return nums[j];
            else{
                if (-nums[i] > nums[j]) i++;
                else j--;
            }
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {-1,2,-3,3};
    // vector<int> nums = {-1,10,6,7,-7,1};
    // vector<int> nums = {-10,8,6,7,-2,-3};
    Solution S;
    cout << S.findMaxK(nums) << endl;
    return 0;
}