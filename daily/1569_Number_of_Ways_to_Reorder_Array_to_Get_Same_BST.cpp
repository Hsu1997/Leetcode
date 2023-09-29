#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int n;
    int mod = 1e9+7;
    vector<vector<long>> permutation;
    
    int dfs(vector<int>& nums){
        int m = nums.size();
        if (m < 3) return 1;
        long ans = 1;
        vector<int> less;
        vector<int> greater;
        for (int i = 1; i < m; i++){
            if (nums[i] < nums[0]) less.push_back(nums[i]);
            else greater.push_back(nums[i]);
        }
        ans *= permutation[m-1][less.size()] * (dfs(less) * dfs(greater) % mod) % mod;
        return ans;
    }

    int numOfWays(vector<int>& nums) {
        n = nums.size();
        permutation = vector<vector<long>>(n+1, vector<long>(n+1, 1));
        for (int i = 1; i <= n; i++){
            for (int j = 1; j < i; j++) permutation[i][j] = (permutation[i-1][j-1] + permutation[i-1][j]) % mod;
        }
        return dfs(nums)-1;
    }
};

int main(){
    vector<int> nums = {2,1,3};
    // vector<int> nums = {3,4,5,1,2};
    // vector<int> nums = {1,2,3};
    Solution S;
    cout << S.numOfWays(nums) << endl;
    return 0;
}