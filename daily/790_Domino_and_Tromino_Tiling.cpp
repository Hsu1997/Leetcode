#include <iostream>

using namespace std;

class Solution {
public:
    int numTilings(int n) {
        int mod = 1e9+7;
        long pre_pre = 1;
        long pre = 1;
        long acc = 2;
        long ans = 1;
        // cout << "1 1 ";
        for (int i = 2; i <= n; i++){
            ans = (acc*2 - pre_pre - pre) % mod;
            while(ans < 0) ans += mod;
            acc = (acc + ans) % mod;
            pre_pre = pre;
            pre = ans;
            // cout << ans << " ";
        }
        // cout << endl;
        return ans;
    }
};

int main(){
    Solution S;
    int n = 3;
    // int n = 1000;
    cout << S.numTilings(n) << endl;
    return 0;
}