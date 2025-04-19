#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        long long countFairPairs(vector<int>& nums, int lower, int upper) {
            int n = nums.size();
            sort(nums.begin(), nums.end());
            int start = n-1;
            int end = n-1;
            long long ans = 0;
            for (int i = 0; i < n; i++){
                if (nums[i] + nums[end] < lower) continue;
                while(start > 0 && nums[i] + nums[start-1] >= lower) start--;
                while(end >= 0 && nums[i] + nums[end] > upper) end--;
                if (end == -1) return ans / 2;
                if (i >= start && i <= end) ans += end - start;
                else ans += end - start + 1;
            }
            return ans / 2;
        }
    };

int main(){
    vector<int> nums = {0,1,7,4,4,5};
    int lower = 3;
    int upper = 6;
    // vector<int> nums = {1,7,9,2,5};
    // int lower = 11;
    // int upper = 11;
    Solution S;
    cout << S.countFairPairs(nums, lower, upper) << endl;
    return 0;
}