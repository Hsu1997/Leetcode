#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = 0;
        int ans = n - 1;
        while(r < n){
            long long threshold = 1LL * nums[l] * k;
            while(r < n && nums[r] <= threshold) r++;
            ans = min(ans, n - (r - l));
            l++;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {2,1,5};
    int k = 2;
    // vector<int> nums = {1,6,2,9};
    // int k = 3;
    // vector<int> nums = {4,6};
    // int k = 2;
    Solution S;
    cout << S.minRemoval(nums, k) << endl;
    return 0;
}