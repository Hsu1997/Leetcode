#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        int curr_limit = -1;
        for (int i = 0; i < n; i++){
            if (nums[i] > curr_limit){
                curr_limit = nums[i] + k;
                ans++;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {3,6,1,2,5};
    int k = 2;
    // vector<int> nums = {1,2,3};
    // int k = 1;
    // vector<int> nums = {2,2,4,5};
    // int k = 0;
    Solution S;
    cout << S.partitionArray(nums, k) << endl;
    return 0;
}