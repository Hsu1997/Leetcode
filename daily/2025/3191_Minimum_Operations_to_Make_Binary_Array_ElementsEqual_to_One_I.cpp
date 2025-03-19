#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n - 2; i++){
            if (nums[i] == 0){
                ans++;
                for (int d = 0; d < 3; d++) nums[i+d] ^= 1;
            }
        }
        if (nums[n-2] == 1 && nums[n-1] == 1) return ans;
        else return -1;
    }
};

int main(){
    vector<int> nums = {0,1,1,1,0,0};
    // vector<int> nums = {0,1,1,1};
    Solution S;
    cout << S.minOperations(nums) << endl;
    return 0;
}