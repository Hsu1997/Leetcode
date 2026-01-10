#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int odd = 0;
        for (int num : nums) odd = (odd + num % 2) % 2;
        return odd? 0 : nums.size() - 1;
    }
};

int main(){
    vector<int> nums = {10,10,3,7,6};
    // vector<int> nums = {1,2,2};
    // vector<int> nums = {2,4,6,8};
    Solution S;
    cout << S.countPartitions(nums) << endl;
    return 0;
}