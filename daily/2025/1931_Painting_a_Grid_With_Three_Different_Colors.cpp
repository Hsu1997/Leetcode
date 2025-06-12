#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int colorTheGrid(int m, int n) {
        int mod = 1e9 + 7;
        int type = pow(3, m);
        vector<vector<int>> color_map(type, vector<int>(m));
        for (int c = 0; c < type; c++){
            int curr = c;
            for (int i = 0; i < m; i++){
                color_map[c][i] = curr % 3;
                curr /= 3;
            }
        }
        vector<int> valid;
        for (int i = 0; i < type; i++){
            bool v = true;
            for (int j = 1; j < m; j++){
                if (color_map[i][j-1] == color_map[i][j]){
                    v = false;
                    break;
                }
            }
            if (v) valid.push_back(i);
        }
        vector<vector<int>> valid_pair(type);
        for (int i : valid){
            for (int j : valid){
                bool v = true;
                for (int c = 0; c < m; c++){
                    if (color_map[i][c] == color_map[j][c]){
                        v = false;
                        break;
                    }
                }
                if (v) valid_pair[i].push_back(j);
            }
        }
        vector<vector<int>> dp(type, vector<int>(n, 0));
        for (int i : valid) dp[i][0] = 1;
        for (int j = 0; j < n - 1; j++){
            for (int i = 0; i < type; i++){
                if (dp[i][j]){
                    for (int next : valid_pair[i]){
                        dp[next][j+1] = (dp[next][j+1] + dp[i][j]) % mod;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < type; i++){
            ans = (ans + dp[i][n-1]) % mod;
        }
        return ans;
    }
};

int main(){
    // int m = 1;
    // int n = 1;
    // int m = 1;
    // int n = 2;
    int m = 5;
    int n = 5;
    Solution S;
    cout << S.colorTheGrid(m, n) << endl;
    return 0;
}