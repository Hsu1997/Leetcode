#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> table;
    int ans;

    void dfs(int i, int j){
        if (table[i][j] != 0) return;
        // cout << i << " " << j << endl;
        table[i][j] = -1;
        if (i == n-1){
            // cout << "!" << endl;
            ans++;
        }
        else{
            // for (int k = 0; k < n; k++) if (k != j) table[i][k] += 1;
            for (int k = i+1; k < n; k++) table[k][j] += 1;
            for (int k = i+1; k < n; k++){
                if (j - (k-i) >= 0) table[k][j-(k-i)] += 1;
                if (j + (k-i) < n) table[k][j+(k-i)] += 1;
            }

            for (int k = 0; k < n; k++) dfs(i+1, k);

            // for (int k = 0; k < n; k++) if (k != j) table[i][k] -= 1;
            for (int k = i+1; k < n; k++) table[k][j] -= 1;
            for (int k = i+1; k < n; k++){
                if (j - (k-i) >= 0) table[k][j-(k-i)] -= 1;
                if (j + (k-i) < n) table[k][j+(k-i)] -= 1;
            }
        }
        table[i][j] = 0;
    }


    int totalNQueens(int _n) {
        n = _n;
        ans = 0;
        table = vector<vector<int>>(n, vector<int>(n, 0));
        // for (auto i : table) for (auto j : i) cout << j << " ";
        
        for (int j = 0; j < n/2; j++){
            // cout << "test" << endl;
            dfs(0, j);
        }
        ans *= 2;
        if (n % 2 == 1) dfs(0, n/2);
        return ans;
    }
};

int main(){
    int n = 4;
    Solution S;
    cout << S.totalNQueens(n) << endl;
    return 0;
}