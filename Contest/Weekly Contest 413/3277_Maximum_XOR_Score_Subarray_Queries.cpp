#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<vector<int>> table(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) table[i][0] = nums[i];
        for (int j = 1; j < n; j++){
            for (int i = 0; i < n-j; i++){
                table[i][j] = table[i][j-1] ^ table[i+1][j-1];
            }
        }
        for (int i = 0; i < n; i++){
            for (int j = 1; j < n - i; j++){
                table[i][j] = max(table[i][j], table[i][j-1]);
            }
        }
        vector<int> results;
        for (auto q : queries){
            int start = q[0];
            int end = q[1];
            int len = end - start + 1;
            int ans = 0;
            for (int k = 0; k < len; k++){
                ans = max(ans, table[start+k][len-k-1]);
            }
            results.push_back(ans);
        }
        return results;
    }
};

int main(){
    vector<int> nums = {2,8,4,32,16,1};
    vector<vector<int>> queries = {{0,2},{1,4},{0,5}};
    // vector<int> nums = {0,7,3,2,8,5,1};
    // vector<vector<int>> queries = {{0,3},{1,5},{2,4},{2,6},{5,6}};
    Solution S;
    vector<int> ans = S.maximumSubarrayXor(nums, queries);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}