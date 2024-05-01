#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<char>> board;
    string word;
    vector<vector<bool>> visited;
    vector<int> x = {-1,0,1,0};
    vector<int> y = {0,1,0,-1};

    bool in_board(int x, int y){
        return x >= 0 && x < board.size() && y >= 0 && y < board[0].size();
    }

    bool dfs(int i, int j, int w){
        if (board[i][j] == word[w]){
            // cout << i << ", " << j << " = " << word[w] << endl;
            visited[i][j] = true;
            if (w == word.length()-1) return true;
            else{
                for (int d = 0; d < 4; d++){
                    if (in_board(i+x[d], j+y[d]) && !visited[i+x[d]][j+y[d]] && dfs(i+x[d], j+y[d], w+1)) return true;
                }
            }
            visited[i][j] = false;
        }
        return false;
    }

    bool exist(vector<vector<char>>& _board, string _word) {
        board = _board;
        word = _word;
        visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if (dfs(i, j, 0)) return true;
            }
        }
        return false;
    }
};

int main(){
    Solution S;
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    // string word = "SEE";
    // string word = "ABCB";

    cout << S.exist(board, word) << endl;
    return 0;
}