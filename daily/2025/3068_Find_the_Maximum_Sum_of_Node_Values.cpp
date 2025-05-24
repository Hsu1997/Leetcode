#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long ans = 0;
        bool changed_odd = false;
        int minimum_diff = INT_MAX;
        for (auto temp : nums){
            int original = temp;
            int transfer = temp ^ k;
            int diff = max(original, transfer) - min(original, transfer);
            minimum_diff = min(minimum_diff, diff);
            if (transfer > original) changed_odd = !changed_odd;
            ans += max(original, transfer);
        }
        if (changed_odd) ans -= minimum_diff;
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,1};
    int k = 3;
    vector<vector<int>> edges = {{0,1},{0,2}};
    // vector<int> nums = {2,3};
    // int k = 7;
    // vector<vector<int>> edges = {{0,1}};
    // vector<int> nums = {7,7,7,7,7,7};
    // int k = 3;
    // vector<vector<int>> edges = {{0,1},{0,2},{0,3},{0,4},{0,5}};
    // vector<int> nums = {24,78,1,97,44};
    // int k = 6;
    // vector<vector<int>> edges = {{0,2},{1,2},{4,2},{3,4}};
    Solution S;
    cout << S.maximumValueSum(nums, k, edges) << endl;
    return 0;
}
