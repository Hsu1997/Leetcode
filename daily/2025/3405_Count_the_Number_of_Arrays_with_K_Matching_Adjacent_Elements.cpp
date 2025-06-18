#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;
const int M = 100001;
long long fact[100001];
long long inv_fact[100001];

class Solution {
public:
    long long qpow(long long x, int n){
        long long res = 1;
        while(n){
            if (n & 1) res = (res * x) % mod;
            x = x * x % mod;
            n >>= 1;
        }
        return res;
    }
    void init_fact(){
        if (fact[0] == 1) return;
        fact[0] = 1;
        for (int i = 1; i < M; i++) fact[i] = fact[i-1] * i % mod;
        // x^(MOD - 1) = 1 % mod (mod is prime)
        // x^(MOD - 2) = 1 / x % mod
        inv_fact[M - 1] = qpow(fact[M - 1], mod - 2);
        for (int i = M - 2; i >= 0; i--){
            inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod;
        }
        return;
    }
    long long cnk(int n, int k){
        return fact[n] * inv_fact[k] % mod * inv_fact[n - k] % mod;
    }
    int countGoodArrays(int n, int m, int k) {
        init_fact();
        long long ans = m * cnk(n-1, k) % mod * qpow(m - 1, n - 1 - k) % mod;
        return ans;
    }
};

int main(){
    int n = 3;
    int m = 2;
    int k = 1;
    // int n = 4;
    // int m = 2;
    // int k = 2;
    // int n = 5;
    // int m = 2;
    // int k = 0;
    // int n = 100000;
    // int m = 100000;
    // int k = 9;
    // int n = 100000;
    // int m = 100000;
    // int k = 99999;
    Solution S;
    cout << S.countGoodArrays(n, m, k) << endl;
    return 0;
}