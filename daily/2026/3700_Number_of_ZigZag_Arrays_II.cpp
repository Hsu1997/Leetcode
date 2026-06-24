#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> mulmatrix(vector<vector<int>>& a, vector<vector<int>>& b){
        int mod = 1e9 + 7;
        int m = a.size();
        int n = a[0].size();
        int l = b[0].size();
        if (b.size() != n) return {};
        vector<vector<int>> ans(m, vector<int>(l));
        for (int i = 0; i < m; i++){
            for (int j = 0; j < l; j++){
                long long res = 0;
                for (int k = 0; k < n; k++){
                    res = (res + 1LL * a[i][k] * b[k][j]) % mod;
                }
                ans[i][j] = res;
            }
        }
        return ans;
    }
    vector<vector<int>> powmatrix(vector<vector<int>> a, int pow){
        if (a.size() != a[0].size()) return {};
        int n = a.size();
        vector<vector<int>> res(n, vector<int>(n));
        for (int i = 0; i < n; i++) res[i][i] = 1;
        while(pow){
            if (pow & 1) res = mulmatrix(res, a);
            a = mulmatrix(a, a);
            pow >>= 1;
        }
        return res;
    }
    int zigZagArrays(int n, int l, int r) {
        int mod = 1e9 + 7;
        int m = (r - l + 1);
        // [up, down][1 ~ m]
        vector<vector<int>> base(1, vector<int>(m * 2, 0));
        for (int i = 0; i < m; i++){
            base[0][i] = i;
            base[0][m + i] = m - 1 - i;
        }
        vector<vector<int>> trans(m * 2, vector<int>(m * 2, 0));
        for (int i = 0; i < m; i++){
            for (int j = m; j < m + i; j++){
                trans[i][j] = 1;
            }
        }
        for (int i = m; i < m * 2; i++){
            for (int j = m - 1; j > i - m; j--){
                trans[i][j] = 1;
            }
        }
        vector<vector<int>> p = powmatrix(trans, n - 2);
        vector<vector<int>> result = mulmatrix(base, p);
        long long ans = 0;
        for (int i = 0; i < m * 2; i++) ans = (ans + result[0][i]) % mod;
        return ans;
    }
};

int main(){
    // int n = 3;
    // int l = 4;
    // int r = 5;
    int n = 3;
    int l = 1;
    int r = 3;
    Solution S;
    cout << S.zigZagArrays(n, l, r) << endl;
    return 0;
}