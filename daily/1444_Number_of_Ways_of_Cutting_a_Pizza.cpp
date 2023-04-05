#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int m = pizza.size();
        int n = pizza[0].size();
        vector<vector<vector<int>>> dp(k+1, vector<vector<int>>(m, vector<int>(n,0)));
        vector<vector<int>> count(m, vector<int>(n,0));
        int mod = 1e9+7;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (pizza[i][j] == 'A') count[i][j] = 1;
            }
        }
        for (int i = 0; i < m; i++){
            for (int j = n-2; j >= 0; j--){
                count[i][j] += count[i][j+1];
            }
        }
        for (int j = 0; j < n; j++){
            for (int i = m-2; i >= 0; i--){
                count[i][j] += count[i+1][j];
            }
        }
        // cout << "apple account  : " << endl;
        // for (auto i : count){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }
        // cout << "cut = " << 1 << " : " << endl;
        // for (auto i : dp[1]){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }
        if (k == 1) return count[0][0] > 0;
        for (int cut = 2; cut <= k; cut++){
            for (int i = 0; i < m; i++){
                for (int j = 0; j < n; j++){
                    // cut horizontal
                    for (int x = i; x < m-1; x++){
                        if (count[i][j] > count[x+1][j] && count[x+1][j]) dp[cut][i][j] += (cut == 2)? 1 : dp[cut-1][x+1][j] % mod;
                        dp[cut][i][j] %= mod;
                        // if (cut == 2 && i == 0 && j == 3 && count[x][j] > count[x+1][j] && count[x+1][j]) cout << "cut horizontal between " << x << " and " << x+1 << ", +" << dp[cut-1][x+1][j] << endl; 
                    }
                    // cut vertical
                    for (int y = j; y < n-1; y++){
                        if (count[i][j] > count[i][y+1] && count[i][y+1]) dp[cut][i][j] += (cut == 2)? 1 : dp[cut-1][i][y+1] % mod;
                        // if (cut == 2 && i == 0 && j == 3 && count[i][y] > count[i][y+1] && count[i][y+1]) cout << "cut vertical between " << y << " and " << y+1 << ", +" << dp[cut-1][i][y+1] << endl; 
                        dp[cut][i][j] %= mod;
                    }
                }
            }
            // cout << "cut = " << cut << " : " << endl;
            // for (auto a : dp[cut]){
            //     for (auto b : a) cout << b << " ";
            //     cout << endl;
            // }
        }
        return dp[k][0][0];
    }
};

int main(){
    // vector<string> pizza = {"A..","AAA","..."};
    // int k = 3;
    // vector<string> pizza = {"A..","AA.","..."};
    // int k = 3;
    // vector<string> pizza = {"A..","A..","..."};
    // int k = 1;
    vector<string> pizza = {".A..A","A.A..","A.AA.","AAAA.","A.AA."};
    int k = 5;
    Solution S;
    cout << S.ways(pizza, k) << endl;
    return 0;
}