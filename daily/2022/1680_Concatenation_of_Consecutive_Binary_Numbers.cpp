#include <iostream>

using namespace std;

class Solution {
public:
    int concatenatedBinary(int n) {
        int mod = 1e9+7;
        long ans = 0;
        int bits_limit = 2;
        int bits_count = 1;
        for (int i = 1; i <= n; i++){
            if (i == bits_limit){
                bits_limit *= 2;
                bits_count++;
                // cout << i << " : " << bits_count << ", " << bits_limit << endl;
            }
            ans <<= bits_count;
            ans %= mod;
            ans += i;
            ans %= mod;
            // cout << "ans = " << ans << endl;
        }
        return ans;
    }
};

int main(){
    int n = 12;
    Solution S;
    cout << S.concatenatedBinary(n) << endl;
    return 0;
}