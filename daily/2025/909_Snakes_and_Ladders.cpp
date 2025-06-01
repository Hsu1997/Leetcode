#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        unordered_map<int,int> ladder;
        int n = board.size();
        for (int row = n - 1; row >= 0; row--){
            for (int col = 0; col < n; col++){
                int row_count = n - 1 - row;
                int col_count = (row_count % 2 == 0)? col + 1 : n - col;
                int index = row_count * n + col_count;
                if (board[row][col] == -1) ladder[index] = index;
                else ladder[index] = board[row][col];
            }
        }
        vector<int> round(n * n + 1, -1);
        queue<int> que;
        round[1] = 0;
        que.push(1);
        int t = 1;
        while(!que.empty()){
            int k = que.size();
            while(k--){
                int temp = que.front();
                que.pop();
                for (int i = 1; i <= 6; i++){
                    int next = ladder[temp + i];
                    if (next == n * n) return t;
                    if (round[next] != -1) continue;
                    round[next] = t;
                    que.push(next);
                }
            }
            t++;
        }
        return -1;
    }
};

int main(){
    vector<vector<int>> board = {{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}};
    // vector<vector<int>> board = {{-1,-1},{-1,3}};
    Solution S;
    cout << S.snakesAndLadders(board) << endl;
    return 0;
}