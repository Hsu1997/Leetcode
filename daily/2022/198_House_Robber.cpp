#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int M = nums[0];
        for (int i = 2; i < n; i++){
            nums[i] += M;
            M = max(M, nums[i-1]);
        }
        return max(M, nums[n-1]);
    }
};

int main(){
    // vector<int> nums = {1,2,3,1};
    // vector<int> nums = {2,7,9,3,1};
    // vector<int> nums = {2};
    vector<int> nums = {2,2};
    Solution S;
    cout << S.rob(nums) << endl;
    return 0;
}