#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long ans = 0;
        int min_positive = INT_MAX;
        int max_negitive = INT_MIN;
        int count = 0;
        for (int i : nums){
            ans += i;
            if ((i^k) - i >= 0){
                ans += ((i^k) - i);
                count++;
                min_positive = min(min_positive, (i^k) - i);
            }
            else{
                max_negitive = max(max_negitive, (i^k) - i);
            }
            // cout << (i^k) - i << " ";
        }
        // cout << endl << "ans = " << ans << ", min_positive = " << min_positive << ", max_negitive = " << max_negitive << endl;
        if (count % 2){
            if (min_positive >= -max_negitive) ans += max_negitive;
            else ans -= min_positive;
        }
        return ans;
    }
};

int main(){
    // vector<int> nums = {1,2,1};
    // int k = 3;
    // vector<vector<int>> edges = {{0,1},{0,2}};
    // vector<int> nums = {2,3};
    // int k = 7;
    // vector<vector<int>> edges = {{0,1}};
    // vector<int> nums = {7,7,7,7,7,7};
    // int k = 3;
    // vector<vector<int>> edges = {{0,1},{0,2},{0,3},{0,4},{0,5}};
    vector<int> nums = {24,78,1,97,44};
    int k = 6;
    vector<vector<int>> edges = {{0,2},{1,2},{4,2},{3,4}};
    Solution S;
    cout << S.maximumValueSum(nums, k, edges) << endl;
    return 0;
}