#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        for (int row = 0; row < n; row++){
            vector<bool> visited(10, false);
            for (int col = 0; col < n; col++){
                if (board[row][col] == '.') continue;
                int curr = board[row][col] - '0';
                if (visited[curr]) return false;
                visited[curr] = true;
            }
        }
        for (int col = 0; col < n; col++){
            vector<bool> visited(10, false);
            for (int row = 0; row < n; row++){
                if (board[row][col] == '.') continue;
                int curr = board[row][col] - '0';
                if (visited[curr]) return false;
                visited[curr] = true;
            }
        }
        for (int row = 0; row < n; row += 3){
            for (int col = 0; col < n; col += 3){
                vector<bool> visited(10, false);
                for (int k = 0; k < 3; k++){
                    for (int l = 0; l < 3; l++){
                        if (board[row + k][col + l] == '.') continue;
                        int curr = board[row + k][col + l];
                        if (visited[curr]) return false;
                        visited[curr] = true;
                    }
                }
            }
        }
        return true;
    }
};

int main(){
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    // vector<vector<char>> board = {{'8','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    Solution S;
    cout << S.isValidSudoku(board) << endl;
    return 0;
}