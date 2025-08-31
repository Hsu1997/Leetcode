#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rows[9] = {0};
    int cols[9] = {0};
    int squares[9] = {0};

    pair<int,int> pos(int idx){ return {idx / 9, idx % 9}; }

    bool dfs(vector<vector<char>>& board, int idx){
        if (idx == 81) return true;
        auto [i, j] = pos(idx);
        int block = i / 3 * 3 + j / 3;
        if (board[i][j] != '.') return dfs(board, idx + 1);
        int used = rows[i] | cols[j] | squares[block];
        for (int k = 0; k < 9; k++){
            if (!(used & (1 << k))){
                rows[i] ^= (1 << k);
                cols[j] ^= (1 << k);
                squares[block] ^= (1 << k);
                board[i][j] = '1' + k;
                if (dfs(board, idx + 1)) return true;
                board[i][j] = '.';
                rows[i] ^= (1 << k);
                cols[j] ^= (1 << k);
                squares[block] ^= (1 << k);
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (board[i][j] == '.') continue;
                int curr = board[i][j] - '1';
                int block = i / 3 * 3 + j / 3;
                rows[i] |= (1 << curr);
                cols[j] |= (1 << curr);
                squares[block] |= (1 << curr);
            }
        }
        dfs(board, 0);
        return;
    }
};

int main(){
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    Solution S;
    S.solveSudoku(board);
    for (auto row : board){
        for (auto col : row){
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}