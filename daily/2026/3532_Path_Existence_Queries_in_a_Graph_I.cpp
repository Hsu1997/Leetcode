#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> farrest(n, 0);
        int curr = 0;
        for (int i = 0; i < n; i++){
            curr = max(curr, i);
            while(curr < n - 1 && nums[curr + 1] - nums[curr] <= maxDiff) curr++;
            farrest[i] = curr;
        }
        int q = queries.size();
        vector<bool> ans(q);
        for (int i = 0; i < q; i++){
            int s = min(queries[i][0], queries[i][1]);
            int e = max(queries[i][0], queries[i][1]);
            ans[i] = (farrest[s] >= e);
        }
        return ans;
    }
};

int main(){
    int n = 2;
    vector<int> nums = {1,3};
    int maxDiff = 1;
    vector<vector<int>> queries = {{0,0},{0,1}};
    // int n = 4;
    // vector<int> nums = {2,5,6,8};
    // int maxDiff = 2;
    // vector<vector<int>> queries = {{0,1},{0,2},{1,3},{2,3}};
    // int n = 2;
    // vector<int> nums = {2975,50642};
    // int maxDiff = 6;
    // vector<vector<int>> queries = {{1,0}};
    Solution S;
    vector<bool> ans = S.pathExistenceQueries(n, nums, maxDiff, queries);
    for (bool i : ans) cout << i << " ";
    cout << endl;
    return 0;
}