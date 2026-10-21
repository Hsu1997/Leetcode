#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        int smaller = 0;
        int larger = 0;
        for (int i = 0; i < n; i++){
            if (nums[i] < target) smaller++;
            else if (nums[i] > target) larger++;
        }
        vector<int> ans;
        for (int i = smaller; i < n - larger; i++) ans.push_back(i);
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,5,2,3};
    int target = 2;
    // vector<int> nums = {1,2,5,2,3};
    // int target = 3;
    // vector<int> nums = {1,2,5,2,3};
    // int target = 5;
    Solution S;
    vector<int> ans = S.targetIndices(nums, target);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}