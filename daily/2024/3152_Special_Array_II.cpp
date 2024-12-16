#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> acc_error(n, 0);
        for (int i = 1; i < n; i++) acc_error[i] = acc_error[i-1] + ((nums[i-1] % 2) == (nums[i] % 2));
        int q = queries.size();
        vector<bool> ans(q);
        for (int i = 0; i < q; i++){
            int start = queries[i][0];
            int end = queries[i][1];
            ans[i] = (acc_error[start] == acc_error[end])? true : false;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {3,4,1,2,6};
    vector<vector<int>> queries = {{0,4}};
    // vector<int> nums = {4,3,1,6};
    // vector<vector<int>> queries = {{0,2},{2,3}};
    // vector<int> nums = {1};
    // vector<vector<int>> queries = {{0,0}};
    Solution S;
    vector<bool> ans = S.isArraySpecial(nums, queries);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}