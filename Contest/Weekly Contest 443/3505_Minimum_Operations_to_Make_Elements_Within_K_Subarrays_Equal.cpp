#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> operations(n - x + 1, -1);
        multiset<int, greater<int>> f;
        multiset<int> s;
        long long sum1 = 0;
        long long sum2 = 0;
        for (int i = 0; i < n; i++){
            int curr = nums[i];
            f.insert(curr);
            sum1 += curr;
            int maximum_min = *f.begin();
            f.erase(f.find(maximum_min));
            s.insert(maximum_min);
            sum1 -= maximum_min;
            sum2 += maximum_min;
            if (i >= x){
                int curr_del = nums[i-x];
                if (f.find(curr_del) != f.end()){
                    f.erase(f.find(curr_del));
                    sum1 -= curr_del;
                }
                else{
                    s.erase(s.find(curr_del));
                    sum2 -= curr_del;
                }
            }
            while(f.size() < s.size()){
                int temp = *s.begin();
                s.erase(s.find(temp));
                f.insert(temp);
                sum2 -= temp;
                sum1 += temp;
            }
            if (i >= x - 1){
                long long median = *f.begin();
                long long op = median * f.size() - sum1 + sum2 - median * s.size();
                operations[i - x + 1] = op;
            }
        }
        // for (auto i : operations) cout << i << " ";
        // cout << endl;
        int opSize = operations.size();
        vector<vector<long long>> dp(k + 1, vector<long long>(opSize, 1e12));
        dp[1][opSize - 1] = operations[opSize - 1];
        for (int j = opSize - 2; j >= 0; j--) dp[1][j] = min(operations[j], dp[1][j+1]);
        for (int i = 2; i <= k; i++){
            for (int j = opSize - 1 - (i - 1) * x; j >= 0; j--){
                dp[i][j] = min(operations[j] + dp[i-1][j + x], dp[i][j+1]);
            }
        }
        // for (auto i : dp){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }
        return dp[k][0];
    }
};

int main(){
    vector<int> nums = {5,-2,1,3,7,3,6,4,-1};
    int x = 3;
    int k = 2;
    // vector<int> nums = {9,-2,-2,-2,1,5};
    // int x = 2;
    // int k = 2;
    Solution S;
    cout << S.minOperations(nums, x, k) << endl;
    return 0;
}