#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int mod = 1e9 + 7;
        int m = r - l + 1;
        vector<int> up(m + 1, 0);
        vector<int> down(m + 1, 0);
        vector<int> accup(m + 1, 0);
        vector<int> accdown(m + 1, 0);
        for (int i = 0; i < m; i++){
            up[i] = i;
            down[i] = m - 1 - i;
        }
        accup[0] = up[0];
        accdown[0] = down[0];
        for (int i = 1; i < m; i++){
            accup[i] = (accup[i-1] + up[i]) % mod;
            accdown[i] = (accdown[i-1] + down[i]) % mod;
        }
        for (int pos = 3; pos <= n; pos++){
            vector<int> tempup(m + 1, 0);
            vector<int> tempdown(m + 1, 0);
            for (int i = 0; i < m; i++){
                tempup[i] = (i == 0)? 0 : accdown[i-1];
                tempdown[i] = (accup[m - 1] - accup[i] + mod) % mod;
            }
            swap(up, tempup);
            swap(down, tempdown);
            accup[0] = up[0];
            accdown[0] = down[0];
            for (int i = 1; i < m; i++){
                accup[i] = (accup[i - 1] + up[i]) % mod;
                accdown[i] = (accdown[i - 1] + down[i]) % mod;
            }
        }
        return (accup[m - 1] + accdown[m - 1]) % mod;
    }
};

int main(){
    int n = 3;
    int l = 4;
    int r = 5;
    // int n = 3;
    // int l = 1;
    // int r = 3;
    Solution S;
    cout << S.zigZagArrays(n, l, r) << endl;
    return 0;
}