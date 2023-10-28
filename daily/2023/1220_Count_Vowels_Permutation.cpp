#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countVowelPermutation(int n) {
        int mod = 1e9+7;
        vector<int> count(5,0);
        vector<int> temp(5,1);
        // "ea", "ia", "ua" 124
        // "ae", "ie" 02
        // "ei", "oi"13
        // "io" 2
        // "iu", "ou" 23
        for (int i = 2; i <= n; i++){
            count[0] = ((temp[1] + temp[2]) % mod + temp[4]) % mod;
            count[1] = (temp[0] + temp[2]) % mod;
            count[2] = (temp[1] + temp[3]) % mod;
            count[3] = (temp[2]) % mod;
            count[4] = (temp[2] + temp[3]) % mod;
            swap(count, temp);
        }
        int ans = 0;
        for (auto i : temp) ans = (ans + i) % mod;
        return ans;
    }
};

int main(){
    // int n = 1;
    // int n = 2;
    int n = 5;
    Solution S;
    cout << S.countVowelPermutation(n) << endl;
    return 0;
}