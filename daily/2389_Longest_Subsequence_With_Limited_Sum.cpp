#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans(queries.size(), 0);
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++){
            nums[i] += nums[i-1];
        }
        for (int i = 0; i < queries.size(); i++){
            ans[i] = upper_bound(nums.begin(), nums.end(), queries[i]) - nums.begin();
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {4,5,2,1};
    vector<int> queries = {3,10,21};
    // vector<int> nums = {2,3,4,5};
    // vector<int> queries = {1};
    Solution S;
    vector<int> ans = S.answerQueries(nums, queries);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}