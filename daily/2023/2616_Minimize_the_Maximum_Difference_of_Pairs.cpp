#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool valid(vector<int>& nums, int threshold, int p){
        if (p == 0) return true;
        int pairs = 0;
        for (int i = 0; i < nums.size()-1; i++){
            if ((nums[i+1] - nums[i]) <= threshold) pairs++, i++;
            if (pairs >= p) return true;
        }
        return false;
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        // for (auto i : nums) cout << i << " ";
        // cout << endl;
        int l = 0;
        int r = nums.back() - nums.front();
        while(l < r){
            int mid = l + (r-l)/2;
            if (valid(nums, mid, p)) r = mid;
            else l = mid+1;
        }
        return r;
    }
};

int main(){
    // vector<int> nums = {10,1,2,7,1,3};
    // int p = 2;
    // vector<int> nums = {4,2,1,2};
    // int p = 1;
    vector<int> nums = {3,4,2,3,2,1,2};
    int p = 3;
    Solution S;
    cout << S.minimizeMax(nums, p) << endl;
    return 0;
}