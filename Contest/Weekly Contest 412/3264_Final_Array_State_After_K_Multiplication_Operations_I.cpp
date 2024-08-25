#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        for (int r = 0; r < k; r++){
            int temp = INT_MAX;
            int index = -1;
            for (int i = 0; i < n; i++){
                if (nums[i] < temp) temp = nums[i], index = i;
            }
            nums[index] *= multiplier;
        }
        return nums;
    }
};

int main(){
    vector<int> nums = {2,1,3,5,6};
    int k = 5;
    int multiplier = 2;
    // vector<int> nums = {1,2};
    // int k = 3;
    // int multiplier = 4;
    Solution S;
    vector<int> ans = S.getFinalState(nums, k, multiplier);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}