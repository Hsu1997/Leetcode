#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater());
        // for (auto i : nums) cout << i << " ";
        // cout << endl;
        for (int i = 0; i < nums.size()-1; i++){
            if (nums[i] >= i+1 && i+1 > nums[i+1]) return i+1;
        }
        if (nums.size() <= nums.back()) return nums.size();
        return -1;
    }
};

int main(){
    vector<int> nums = {3,5};
    // vector<int> nums = {0,0};
    // vector<int> nums = {0,4,3,0,4};
    // vector<int> nums = {1,0,0,6,4,9};
    Solution S;
    cout << S.specialArray(nums) << endl;
    return 0;
}