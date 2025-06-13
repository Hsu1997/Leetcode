#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool valid(vector<int>& nums, int p, int d){
        if (p == 0) return true;
        int found = 0;
        int i = 0;
        int n = nums.size();
        while(i < n - 1){
            if (abs(nums[i] - nums[i+1]) <= d){
                found++;
                if (found >= p) return true;
                i += 2;
            }
            else i++;
        }
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.back() - nums[0];
        int ans = INT_MAX;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if (valid(nums, p, mid)){
                ans = min(ans, mid);
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {10,1,2,7,1,3};
    int p = 2;
    // vector<int> nums = {4,2,1,2};
    // int p = 1;
    // vector<int> nums = {0,5,3,4};
    // int p = 0;
    Solution S;
    cout << S.minimizeMax(nums, p) << endl;
    return 0;
}