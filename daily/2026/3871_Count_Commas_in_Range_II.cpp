#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long minus = 999;
        n -= minus;
        while(n > 0){
            ans += n;
            minus *= 1000;
            n -= minus;
        }
        return ans;
    }
};

int main(){
    long long n = 1002;
    // long long n = 998;
    // long long n = 34823849238328;
    // long long n = 39934892348923;
    // long long n = 99999999999999;
    // long long n = 38283934294;
    Solution S;
    cout << S.countCommas(n) << endl;
    return 0;
}