#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int acc = 0;
        int pre = 0;
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++){
            acc = (acc + nums[i]) % k;
            if (s.find(acc) != s.end()) return true;
            else{
                s.insert(pre);
                pre = acc;
            }
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
    vector<int> nums = {23,2,4,6,6};
    int k = 7;
    Solution S;
    cout << S.checkSubarraySum(nums, k) << endl;
    return 0;
}