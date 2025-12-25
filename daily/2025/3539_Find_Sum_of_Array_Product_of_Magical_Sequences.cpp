#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long mod = 1e9 + 7;

    long long modPow(long long base, long long pow){
        long long res = 1;
        while(pow){
            if (pow % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            pow >>= 1;
        }
        return res;
    };

    int magicalSum(int m, int k, vector<int>& nums){
        int n = nums.size();
        if (m < 1) return 0;
        vector<long long> fac(m + 1, 0);
        vector<long long> ifac(m + 1, 0);
        fac[0] = 1;
        ifac[0] = 1;
        for (int i = 1; i <= m; i++) fac[i] = (i * fac[i-1]) % mod;
        // Fermat's Little Theorem
        // a ^ (p - 1) == 1 % p when p is prime numbers
        // a ^ (mod - 1) == 1 % mod
        // a ^ (mod - 2) == (1 / a) % mod
        for (int i = 1; i <= m; i++) ifac[i] = modPow(i, mod - 2);
        for (int i = 2; i <= m; i++) ifac[i] = (ifac[i] * ifac[i-1]) % mod;
        vector<vector<long long>> numPow(n, vector<long long>(m + 1, 1));
        for (int i = 0; i < n; i++){
            for (int j = 1; j <= m; j++){
                numPow[i][j] = (nums[i] * numPow[i][j-1]) % mod;
            }
        }

        // [index 0 ~ index idx already done][already taken][carry][accumulate bits until ith idx (idx < i, not include)]
        // [n][m+1][m+1][k+1]
        vector<vector<vector<vector<long long>>>> dp(n, 
            vector<vector<vector<long long>>>(m + 1, 
                vector<vector<long long>>(m + 1, 
                    vector<long long>(k + 1, 0))));
        // Start from i == 0
        for (int j = 0; j <= m; j++){
            int p = j;
            dp[0][j][p][0] = (numPow[0][j] * ifac[j]) % mod;
        }
        for (int i = 0; i + 1 < n; i++){
            for (int j = 0; j <= m; j++){
                for (int p = 0; p <= m; p++){
                    for (int q = 0; q <= k; q++){
                        long long curr = dp[i][j][p][q];
                        if (curr == 0) continue;
                        // count carry to acc bits
                        int q2 = q + (p & 1);
                        if (q2 > k) continue;
                        for (int take = 0; take + j <= m; take++){
                            int p2 = (p >> 1) + take;
                            long long add = curr;
                            add = (add * numPow[i+1][take]) % mod;
                            add = (add * ifac[take]) % mod;
                            long long &next = dp[i + 1][j + take][p2][q2];
                            next = (next + add) % mod;
                        }
                    }
                }
            }
        }
        long long ans = 0;
        // [n-1][m][p][q] __popcount(p) + q == k
        for (int p = 0; p <= m; p++){
            for (int q = 0; q <= k; q++){
                if (__builtin_popcount(p) + q == k) ans = (ans + (dp[n-1][m][p][q] * fac[m]) % mod) % mod ;
            }
        }
        return ans;
    }
};

int main(){
    int m = 5;
    int k = 5;
    vector<int> nums = {1,10,100,10000,1000000};
    // int m = 2;
    // int k = 2;
    // vector<int> nums = {5,4,3,2,1};
    // int m = 1;
    // int k = 1;
    // vector<int> nums = {28};
    Solution S;
    cout << S.magicalSum(m, k, nums) << endl;
    return 0;
}