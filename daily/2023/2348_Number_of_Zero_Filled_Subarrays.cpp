#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int continue_size = 0;
        long long ans = 0;
        for (auto i : nums){
            if (i == 0) continue_size++;
            else continue_size = 0;
            ans += continue_size;
        }
        return ans;
    }
};

int main(){ 
    vector<int> nums = {1,3,0,0,2,0,0,4};
    // vector<int> nums = {0,0,0,2,0,0};
    // vector<int> nums = {2,10,2019};
    Solution S;
    cout << S.zeroFilledSubarray(nums) << endl;
    return 0;
}