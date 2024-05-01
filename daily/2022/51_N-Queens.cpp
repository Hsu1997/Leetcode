#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> table;
    vector<vector<string>> ans;

    void record(){
        vector<string> temp(n, string(n, '.'));

        // for (auto i : table){
        //     for (auto j : i){
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (table[i][j] == -1) temp[i][j] = 'Q';
            }
        }
        ans.push_back(temp);
    }

    void dfs(int i, int j){
        if (table[i][j] != 0) return;
        // cout << i << " " << j << endl;
        table[i][j] = -1;
        if (i == n-1){
            // cout << "!" << endl;
            record();
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


    vector<vector<string>> solveNQueens(int _n) {
        n = _n;
        table = vector<vector<int>>(n, vector<int>(n, 0));
        // for (auto i : table) for (auto j : i) cout << j << " ";
        
        for (int j = 0; j < n; j++){
            // cout << "test" << endl;
            dfs(0, j);
        }
        return ans;
    }
};

int main(){
    int n = 4;
    Solution S;
    vector<vector<string>> ans = S.solveNQueens(n);
    for (auto i : ans){
        for (auto j : i) cout << j << endl;
        cout << string(n, '-') << endl;
    }
    return 0;
}