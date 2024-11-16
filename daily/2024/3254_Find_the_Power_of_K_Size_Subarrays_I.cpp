#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (k == 1) return nums;
        int n = nums.size();
        vector<int> ans(n-k+1, -1);
        int consecutive = 1;

        for (int i = 1; i < k-1; i++){
            if (nums[i] == nums[i-1] + 1) consecutive++;
            else consecutive = 1;
        }
        for (int i = k-1; i < n; i++){
            if (nums[i] == nums[i-1] + 1) consecutive++;
            else consecutive = 1;
            if (consecutive == k) ans[i-k+1] = nums[i], consecutive--;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,3,4,3,2,5};
    int k = 3;
    // vector<int> nums = {2,2,2,2,2};
    // int k = 4;
    // vector<int> nums = {3,2,3,2,3,2};
    // int k = 2;
    Solution S;
    vector<int> ans = S.resultsArray(nums, k);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}