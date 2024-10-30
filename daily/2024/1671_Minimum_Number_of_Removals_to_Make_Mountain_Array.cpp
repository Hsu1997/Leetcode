#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        int ans = n;
        vector<int> left_to_right(n, 1);
        vector<int> right_to_left(n, 1);
        vector<int> temp = {nums[0]};
        for (int i = 1; i < n; i++){
            auto it = lower_bound(temp.begin(), temp.end(), nums[i]);
            if (it == temp.end()) temp.push_back(nums[i]);
            else *it = nums[i];
            left_to_right[i] = temp.size();
        }
        temp = {nums[n-1]};
        for (int i = n - 2; i >= 0; i--){
            auto it = lower_bound(temp.begin(), temp.end(), nums[i]);
            if (it == temp.end()) temp.push_back(nums[i]);
            else *it = nums[i];
            right_to_left[i] = temp.size();
        }
        for (int i = 1; i < n - 1; i++){
            if (left_to_right[i] > 1 && right_to_left[i] > 1) ans = min(ans, n - left_to_right[i] - right_to_left[i] + 1);
        }
        return ans;
    }
};

int main(){
    // vector<int> nums = {1,3,1};
    // vector<int> nums = {2,1,1,5,6,2,3,1};
    vector<int> nums = {100,92,89,77,74,66,64,66,64};
    Solution S;
    cout << S.minimumMountainRemovals(nums) << endl;
    return 0;
}