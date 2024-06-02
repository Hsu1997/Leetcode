#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int checkRecord(int n) {
        int mod = 1e9 + 7;
        int zeroL = 1;
        int oneL = 1;
        int twoL = 0;
        int azeroL = 1;
        int aoneL = 0;
        int atwoL = 0;
        int temp;
        for (int i = 2; i <= n; i++){
            temp = azeroL % mod;
            azeroL = (((zeroL + oneL) % mod + twoL) % mod + (((azeroL + aoneL) % mod + atwoL) % mod) % mod) % mod;
            atwoL = aoneL % mod;
            aoneL = temp % mod;
            temp = oneL % mod;
            oneL = zeroL % mod;
            zeroL = ((zeroL + temp) % mod + twoL) % mod;
            twoL = temp;
        }
        return (((((zeroL + oneL) % mod + twoL) % mod + azeroL) % mod + aoneL) % mod + atwoL) % mod;
    }
};

int main(){
    // int n = 2;
    // int n = 1;
    int n =10101;
    Solution S;
    cout << S.checkRecord(n) << endl;
    return 0;
}