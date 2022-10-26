#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) return false;

        vector<int> acc(nums.size(), 0);
        acc[0] = nums[0] % k;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i-1] == 0 && nums[i] == 0) return true;
            acc[i] = (acc[i-1] + nums[i]) % k;
            if (nums[i] != 0 && acc[i] == 0) return true;
        }
        set<int> S;
        S.insert(acc[0]);
        for (int i = 2; i < acc.size(); i++){
            if (S.count(acc[i])) return true;
            S.insert(acc[i-1]);
        }
        return false;
    }
};

int main(){
    // vector<int> nums = {23,2,4,6,7};
    // int k = 6;
    // vector<int> nums = {23,2,6,4,7};
    // int k = 6;
    // vector<int> nums = {23,2,6,4,7};
    // int k = 13;
    // vector<int> nums = {1,0,1,0,1};
    // int k = 4;
    vector<int> nums = {23,3,3};
    int k = 6;
    Solution S;
    cout << S.checkSubarraySum(nums, k) << endl;
    return 0;
}