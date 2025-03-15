#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool valid(vector<int>& nums, int k, int val){
        int n = nums.size();
        int choosen = 0;
        for (int i = 0; i < n; i++){
            if (nums[i] <= val) choosen++, i++;
            if (choosen == k) return true;
        }
        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        int ans = INT_MAX;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if (valid(nums, k, mid)){
                ans = min(ans, mid);
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {2,3,5,9};
    int k = 2;
    // vector<int> nums = {2,7,9,3,1};
    // int k = 2;
    Solution S;
    cout << S.minCapability(nums, k) << endl;
    return 0;
}