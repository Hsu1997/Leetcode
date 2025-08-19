#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt = 0;
        int contiguous = 0;
        for (int num : nums){
            if (num == 0) contiguous++;
            else contiguous = 0;
            cnt += contiguous;
        }
        return cnt;
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