#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int acc = 0;
        int ans = 0;
        int n = nums.size();
        vector<bool> seen(10001, false);
        int ptr = 0;
        for (int i = 0; i < n; i++){
            if (seen[nums[i]]){
                while(ptr < n && nums[ptr] != nums[i]){
                    acc -= nums[ptr];
                    seen[nums[ptr]] = false;
                    ptr++;
                }
                acc -= nums[ptr];
                ptr++;
            }
            seen[nums[i]] = true;
            acc += nums[i];
            ans = max(ans, acc);
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {4,2,4,5,6};
    // vector<int> nums = {5,2,1,2,5,2,1,2,5};
    // vector<int> nums = {10000};
    // vector<int> nums = {187,470,25,436,538,809,441,167,477,110,275,133,666,345,411,459,490,266,987,965,429,166,809,340,467,318,125,165,809,610,31,585,970,306,42,189,169,743,78,810,70,382,367,490,787,670,476,278,775,673,299,19,893,817,971,458,409,886,434};
    Solution S;
    cout << S.maximumUniqueSubarray(nums) << endl;
    return 0;
}