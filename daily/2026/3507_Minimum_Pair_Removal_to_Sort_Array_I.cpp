#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n);
        iota(next.begin(), next.end(), 1);
        next[n-1] = -1;
        int ans = 0;
        while(n - ans > 1){
            int curr = 0;
            int target = 0;
            int targetSum = nums[target] + nums[next[target]];
            bool nonDecreasing = true;
            while(curr != -1 && next[curr] != -1){
                if (nums[curr] > nums[next[curr]]) nonDecreasing = false;
                if (nums[curr] + nums[next[curr]] < targetSum){
                    target = curr;
                    targetSum = nums[curr] + nums[next[curr]];
                }
                curr = next[curr];
            }
            if (nonDecreasing) return ans;
            nums[target] += nums[next[target]];
            next[target] = next[next[target]];
            ans++;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {5,2,3,1};
    // vector<int> nums = {1,2,2};
    // vector<int> nums = {-1};
    Solution S;
    cout << S.minimumPairRemoval(nums) << endl;
    return 0;
}