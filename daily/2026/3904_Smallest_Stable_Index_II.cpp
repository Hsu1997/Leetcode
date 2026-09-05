#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n, 0);
        res[n-1] = nums[n-1];
        for (int i = n - 2; i >= 0; i--){
            res[i] = min(nums[i], res[i+1]);
        }
        int M = 0;
        for (int i = 0; i < n; i++){
            M = max(M, nums[i]);
            if (M - res[i] <= k) return i;
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {5,0,1,4};
    int k = 3;
    // vector<int> nums = {3,2,1};
    // int k = 1;
    // vector<int> nums = {0};
    // int k = 0;
    Solution S;
    cout << S.firstStableIndex(nums, k) << endl;
    return 0;
}