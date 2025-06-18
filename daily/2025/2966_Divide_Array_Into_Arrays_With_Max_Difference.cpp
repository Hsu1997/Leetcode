#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i += 3){
            if (nums[i+2] - nums[i] > k) return {};
            ans.push_back({nums[i], nums[i+1], nums[i+2]});
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,3,4,8,7,9,3,5,1};
    int k = 2;
    // vector<int> nums = {2,4,2,2,5,2};
    // int k = 2;
    // vector<int> nums = {4,2,9,8,2,12,7,12,10,5,8,5,5,7,9,2,5,11};
    // int k = 14;
    Solution S;
    vector<vector<int>> ans = S.divideArray(nums, k);
    for (auto v : ans){
        cout << "{ ";
        for (int i : v) cout << i << " ";
        cout << "} ";
    }
    cout << endl;
    return 0;
}