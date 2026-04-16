#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int,int> m;
        vector<int> dis(n, INT_MAX);
        for (int i = 0; i < n; i++) m[nums[i]] = -n + i;
        for (int i = 0; i < n; i++){
            dis[i] = i - m[nums[i]];
            m[nums[i]] = i;
        }
        for (int i = n - 1; i >= 0; i--) m[nums[i]] = n + i;
        for (int i = n - 1; i >= 0; i--){
            dis[i] = min(dis[i], m[nums[i]] - i);
            m[nums[i]] = i;
        }
        for (int i = 0; i < n; i++) if (dis[i] == n) dis[i] = -1;
        int q = queries.size();
        vector<int> ans(q);
        for (int i = 0; i < q; i++) ans[i] = dis[queries[i]];
        return ans;
    }
};

int main(){
    vector<int> nums = {1,3,1,4,1,3,2};
    vector<int> queries = {0,3,5};
    // vector<int> nums = {1,2,3,4};
    // vector<int> queries = {0,1,2,3};
    Solution S;
    vector<int> ans = S.solveQueries(nums, queries);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}