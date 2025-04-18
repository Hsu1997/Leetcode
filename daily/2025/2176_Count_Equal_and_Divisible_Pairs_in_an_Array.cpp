#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                if (nums[i] == nums[j] && i * j % k == 0) ans++;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {3,1,2,2,2,1,3};
    int k = 2;
    // vector<int> nums = {1,2,3,4};
    // int k = 1;
    Solution solution;
    cout << solution.countPairs(nums, k) << endl;
    return 0;
}