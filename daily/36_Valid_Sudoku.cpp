#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int count;
        
        for(int i = 0; i < 9; i++){
            count = 0;
            for (int j = 0; j < 9; j++){
                if (board[i][j] == '.') continue;
                if (1 << (board[i][j] - '0') & count) return false;
                count |= (1 << (board[i][j] - '0'));
            }
        }

        for(int j = 0; j < 9; j++){
            count = 0;
            for (int i = 0; i < 9; i++){
                if (board[i][j] == '.') continue;
                if (1 << (board[i][j] - '0') & count) return false;
                count |= (1 << (board[i][j] - '0'));
            }
        }
        
        for (int x = 0; x < 9; x += 3){
            for (int y = 0; y < 9; y += 3){
                count = 0;
                for (int i = x; i < x+3; i++){
                    for (int j = y; j < y+3; j++){
                        if (board[i][j] == '.') continue;
                        if (1 << (board[i][j] - '0') & count) return false;
                        count |= (1 << (board[i][j] - '0'));
                    }
                }
            }
        }

        return true;

        // vector<vector<int>> b(9, vector<int>(9, 0));
        // for (int i = 0; i < 9; i++){
        //     for (int j = 0; j < 9; j++){
        //         b[i][j] = (board[i][j] == '.')? 0 : (board[i][j] - '0');
        //     }
        // }

        // for (int i = 0; i < 9; i++){
        //     vector<int> count(10,0);
        //     for (int j = 0; j < 9; j++){
        //         count[b[i][j]]++;
        //     }

        //     // for (auto k : count) cout << k << " ";
        //     // cout << endl;
        //     for (int k = 1; k <= 9; k++) if (count[k] > 1) return false;
        // }

        // // cout << "-------------------" << endl;

        // for (int j = 0; j < 9; j++){
        //     vector<int> count(10,0);
        //     for (int i = 0; i < 9; i++){
        //         count[b[i][j]]++;
        //     }

        //     // for (auto k : count) cout << k << " ";
        //     // cout << endl;
        //     for (int k = 1; k <= 9; k++) if (count[k] > 1) return false;
        // }

        // // cout << "-------------------" << endl;

        // for (int i = 0; i < 9; i+=3){
        //     for (int j = 0; j < 9; j+=3){
        //         int startx = i;
        //         int starty = j;
        //         vector<int> count(10,0);
        //         for (int x = i; x < i+3; x++){
        //             for (int y = j; y < j+3; y++){
        //                 count[b[x][y]]++;
        //             }
        //         }

        //         // for (auto k : count) cout << k << " ";
        //         // cout << endl;
        //         for (int k = 1; k <= 9; k++) if (count[k] > 1) return false;
        //     }
        // }

        // return true;
    }
};

int main(){
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'}
                                 ,{'6','.','.','1','9','5','.','.','.'}
                                 ,{'.','9','8','.','.','.','.','6','.'}
                                 ,{'8','.','.','.','6','.','.','.','3'}
                                 ,{'4','.','.','8','.','3','.','.','1'}
                                 ,{'7','.','.','.','2','.','.','.','6'}
                                 ,{'.','6','.','.','.','.','2','8','.'}
                                 ,{'.','.','.','4','1','9','.','.','5'}
                                 ,{'.','.','.','.','8','.','.','7','9'}};
    Solution S;
    cout << S.isValidSudoku(board) << endl;
    return 0;
}