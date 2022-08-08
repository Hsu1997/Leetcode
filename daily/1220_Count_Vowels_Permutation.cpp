#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countVowelPermutation(int n) {
        int mod = 1e9+7;
        int a = 1, e = 1, i = 1, o = 1, u = 1;
        int an = 1, en = 1, in = 1, on = 1, un = 1;

        for (int k = 1; k < n; k++){
            an = ((e + i) % mod + u % mod) % mod;
            en = (a + i) % mod;
            in = (e + o) % mod;
            on = i;
            un = (i + o) % mod;

            a = an, e = en, i = in, o = on, u = un;
        }

        int ans = (((((a + e) % mod) + i) % mod + o) % mod + u) % mod;
        return ans;
    }
};

int main(){
    int n = 20000;
    Solution S;
    cout << S.countVowelPermutation(n) << endl;
    return 0;
}