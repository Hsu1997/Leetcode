#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTilings(int n) {
        int mod = 1e9 + 7;
        if (n == 1) return 1;
        if (n == 2) return 2;
        vector<long long> a(n+1, 0);
        vector<long long> b(n+1, 0);
        a[0] = 1;
        a[1] = 1;
        a[2] = 2;
        b[0] = 0;
        b[1] = 2;
        b[2] = 4;
        for (int i = 3; i <= n; i++){
            a[i] = (1LL * a[i-1] + a[i-2] + b[i-2]) % mod;
            b[i] = (2LL * a[i-1] + b[i-1]) % mod;
        }
        return a[n];
    }
};

int main(){
    int n = 3;
    // int n = 1;
    // int n = 500;
    // int n = 878;
    // int n = 1000;
    Solution S;
    cout << S.numTilings(n) << endl;
    return 0;
}