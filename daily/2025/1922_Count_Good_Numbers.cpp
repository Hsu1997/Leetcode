#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long mod = 1e9 + 7;
    int countGoodNumbers(long long n) {
        return pow_long(5, (n+1) / 2) * pow_long(4, n / 2) % mod;
    }
    long long pow_long(long long base, long long power){
        long long res = 1;
        while(power){
            if (power % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            power /= 2;
        }
        return res;
    }
};

int main(){
    long long n = 1;
    // long long n = 4;
    // long long n = 50;
    // long long n = 1000000000000000;
    Solution S;
    cout << S.countGoodNumbers(n) << endl;
    return 0;
}