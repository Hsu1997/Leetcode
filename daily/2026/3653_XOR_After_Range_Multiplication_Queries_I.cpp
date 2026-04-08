#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        long long mod = 1e9 + 7;
        for (vector<int>& q : queries){
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];
            for (int i = l; i <= r; i += k){
                nums[i] = (1LL * nums[i] * v) % mod;
            }
        }
        int ans = 0;
        for (int i : nums) ans ^= i;
        return ans;
    }
};

int main(){
    vector<int> nums = {1,1,1};
    vector<vector<int>> queries = {{0,2,1,4}};
    // vector<int> nums = {2,3,1,5,4};
    // vector<vector<int>> queries = {{1,4,2,3},{0,2,1,2}};
    Solution S;
    cout << S.xorAfterQueries(nums, queries) << endl;
    return 0;
}