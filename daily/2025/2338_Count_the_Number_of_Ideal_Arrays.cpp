#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int idealArrays(int n, int maxValue) {
        int mod = 1e9 + 7;
        vector<int> largest_prime(maxValue + 1);
        for (int i = 2; i <= maxValue; i++){
            if (largest_prime[i] == 0){
                for (int j = i; j <= maxValue; j += i){
                    largest_prime[j] = i;
                }
            }
        }

        vector<vector<int>> prime_factor_power(maxValue+1);
        for (int i = 2; i <= maxValue; i++){
            int temp = i;
            while(temp > 1){
                int factor = largest_prime[temp];
                int power = 0;
                while(temp % factor == 0){
                    power++;
                    temp /= factor;
                }
                prime_factor_power[i].push_back(power);
            }
        }

        // 2^14 = 16384, so max power of prime is 14 
        vector<vector<int>> c(n - 1 + 15, vector<int>(15));
        c[0][0] = 1;
        for (int i = 1; i < n + 14; i++){
            c[i][0] = 1;
            for (int j = 1; j <= min(i, 14); j++){
                c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
            }
        }
        long long ans = 0;
        /* 
        We have n positions, and we only need to decide how to distribute the power of each prime across these positions
        (treating it as if every number that comes after inherits this factor because it's incressing array).
        Example : If a prime has a power of p, and the total across the n positions must sum up to p,
        then the number of ways to do this is C(n - 1 + p, p).
        */
        for (int max_element = 1; max_element <= maxValue; max_element++){
            long long mul = 1;
            for (int power : prime_factor_power[max_element]){
                mul = mul * c[n - 1 + power][power] % mod;
            }
            ans = (ans + mul) % mod;
        }
        return ans;
    }
};

int main(){
    int n = 2;
    int maxValue = 5;
    // int n = 5;
    // int maxValue = 3;
    Solution S;
    cout << S.idealArrays(n, maxValue) << endl;
    return 0;
}