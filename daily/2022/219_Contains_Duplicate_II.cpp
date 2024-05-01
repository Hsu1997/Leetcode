#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int i = 0; i < nums.size(); i++){
            if (count[nums[i]]) return true;
            count[nums[i]]++;
            if (i - k >= 0) count[nums[i-k]]--;
        }
        return false;
    }
};

int main(){
    // vector<int> nums = {1,2,3,1};
    // int k = 3;
    // vector<int> nums = {1,0,1,1};
    // int k = 1;
    vector<int> nums = {1,2,3,1,2,3};
    int k = 2;
    Solution S;
    cout << S.containsNearbyDuplicate(nums, k) << endl;
    return 0;
}