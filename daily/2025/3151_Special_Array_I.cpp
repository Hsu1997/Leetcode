#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++){
            if (!((nums[i] % 2) ^ (nums[i-1] % 2))) return false;
        }
        return true;
    }
};

int main(){
    vector<int> nums = {1};
    // vector<int> nums = {2,1,4};
    // vector<int> nums = {4,3,1,6};
    Solution S;
    cout << S.isArraySpecial(nums) << endl;
    return 0;
}