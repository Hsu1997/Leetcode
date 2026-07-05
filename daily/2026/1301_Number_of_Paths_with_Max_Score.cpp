#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int mod = 1e9 + 7;
        board[0][0] = '0';
        board[n-1][n-1] = '0';
        vector<vector<int>> v(n, vector<int>(n, -1));
        vector<vector<int>> cnt(n, vector<int>(n, 0));
        v[0][0] = 0;
        cnt[0][0] = 1;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if ((i == 0 && j == 0) || board[i][j] == 'X') continue;
                int curr_v = board[i][j] - '0';
                int source_max = -1;
                if (i > 0) source_max = max(source_max, v[i-1][j]);
                if (j > 0) source_max = max(source_max, v[i][j-1]);
                if (i > 0 && j > 0) source_max = max(source_max, v[i-1][j-1]);
                if (source_max != -1) v[i][j] = source_max + curr_v;
                else continue;
                if (i > 0 && v[i-1][j] == source_max) cnt[i][j] = (cnt[i][j] + cnt[i-1][j]) % mod;
                if (j > 0 && v[i][j-1] == source_max) cnt[i][j] = (cnt[i][j] + cnt[i][j-1]) % mod;
                if (i > 0 && j > 0 && v[i-1][j-1] == source_max) cnt[i][j] = (cnt[i][j] + cnt[i-1][j-1]) % mod;
            }
        }
        if (v[n-1][n-1] != -1) return {v[n-1][n-1], cnt[n-1][n-1]};
        else return {0, 0};
    }
};

int main(){
    vector<string> board = {"E23","2X2","12S"};
    // vector<string> board = {"E12","1X1","21S"};
    // vector<string> board = {"E11","XXX","11S"};
    Solution S;
    vector<int> ans = S.pathsWithMaxScore(board);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}