#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int count_life(vector<vector<int>>& board, int x, int y){
        int count = 0;
        for (int i = -1; i < 2; i++){
            for (int j = -1; j < 2; j++){
                if (i == 0 && j == 0) continue;
                int new_x = x + i;
                int new_y = y + j;
                if (new_x < 0 || new_x >= board.size() || new_y < 0 || new_y >= board[0].size()) continue;
                // 0:dead 1:live
                // 2:previous is live, but is dead in next round
                // 3:previous is dead, but is live in next round
                if (board[new_x][new_y] == 1 || board[new_x][new_y] == 2) count++;
            }
        }
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        // vector<vector<int>> ans(board.size(), vector<int>(board[0].size()));
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                int temp = count_life(board, i, j);
                if (board[i][j]){
                    if (temp == 2 || temp == 3) board[i][j] = 1;
                    else board[i][j] = 2;
                }
                else{
                    if (temp == 3) board[i][j] = 3;
                    else board[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if (board[i][j] == 2) board[i][j] = 0;
                if (board[i][j] == 3) board[i][j] = 1;
            }
        }
    }
};

int main(){
    vector<vector<int>> board = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    Solution S;
    S.gameOfLife(board);
    for (auto i : board){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}