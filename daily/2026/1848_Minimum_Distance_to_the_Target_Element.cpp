#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        for (int i = 0; i < n; i++){
            if (start - i >= 0 && nums[start - i] == target) return i;
            if (start + i < n && nums[start + i] == target) return i;
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {1,2,3,4,5};
    int target = 5;
    int start = 3;
    // vector<int> nums = {1};
    // int target = 1;
    // int start = 0;
    // vector<int> nums = {1,1,1,1,1,1,1,1,1,1};
    // int target = 1;
    // int start = 0;
    Solution S;
    cout << S.getMinDistance(nums, target, start) << endl;
    return 0;
}