#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countBalancedPermutations(string num) {
        long long mod = 1e9 + 7;
        int total = 0;
        int n = num.length();
        vector<int> count(10);
        for (char c : num){
            int temp = c - '0';
            total += temp;
            count[temp]++;
        }
        if (total % 2 == 1) return 0;
        int MaxOdd = (n + 1) / 2;
        int target = total / 2;
        vector<vector<long long>> combination(MaxOdd + 1, vector<long long>(MaxOdd + 1, 0));
        for (int i = 0; i <= MaxOdd; i++){
            combination[i][0] = 1;
            combination[i][i] = 1;
            for (int j = 1; j < i; j++) combination[i][j] = (combination[i-1][j-1] + combination[i-1][j]) % mod;
        }
        vector<int> suffix(11);
        for (int i = 9; i >= 0; i--) suffix[i] = count[i] + suffix[i+1];
        vector<vector<vector<long long>>> dp(10, vector<vector<long long>>(target + 1, vector<long long>(MaxOdd + 1, -1)));
        
        function<long long(int, int, int)> dfs = [&](int num, int currSum, int oddRemain){
            if (oddRemain < 0 || currSum > target || suffix[num] < oddRemain) return 0LL;
            if (num == 10) return (currSum == target && oddRemain == 0)? 1LL : 0LL;
            if (dp[num][currSum][oddRemain] != -1) return dp[num][currSum][oddRemain];
            int evenRemain = suffix[num] - oddRemain;
            long long res = 0;
            for (int take = max(0, count[num] - evenRemain); take <= min(count[num], oddRemain); take++){
                res += (((combination[oddRemain][take] * combination[evenRemain][count[num] - take]) % mod) * dfs(num + 1, currSum + take * num, oddRemain - take)) % mod;
                res %= mod;
            }
            return dp[num][currSum][oddRemain] = res;
        };
        
        return dfs(0, 0, MaxOdd);
    }
};

int main(){
    string num = "123";
    // string num = "112";
    // string num = "12345";
    Solution S;
    cout << S.countBalancedPermutations(num) << endl;
    return 0;
}