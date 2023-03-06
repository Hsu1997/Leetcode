#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int n;

    vector<int> num_to_coordinate(int num){
        int row = n - 1 - (num-1)/n;
        int col = (num-1) % n;
        if ((n-1-row) % 2 == 1) col = (n-1) - col;
        return {row, col};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        int size = n*n;
        // for (int i = 1; i <= size; i++){
        //     cout << num_to_coordinate(i)[0] << " " << num_to_coordinate(i)[1] << endl;
        // }
        queue<int> que;
        que.push(1);
        vector<bool> visited(size+1, false);
        int round = 0;
        while(!que.empty()){
            int que_size = que.size();
            while(que_size--){
                int temp = que.front();
                que.pop();
                if (temp == size) return round;
                for (int i = temp+1; i <= size && i <= temp+6; i++){
                    if (!visited[i]){
                        vector<int> temp_pos = num_to_coordinate(i);
                        int temp_row = temp_pos[0];
                        int temp_col = temp_pos[1];
                        visited[i] = true;
                        if (board[temp_row][temp_col] == -1) que.push(i);
                        else que.push(board[temp_row][temp_col]);
                    }
                }
            }
            round++;
        }
        return -1;
    }
};

int main(){
    // vector<vector<int>> board = {{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}};
    // vector<vector<int>> board = {{-1,-1},{-1,3}};
    vector<vector<int>> board = {{-1,33,-1,-1,-1,-1,-1,-1},{5,-1,-1,-1,-1,49,-1,-1},{-1,-1,-1,31,-1,-1,54,43},{-1,-1,26,13,41,-1,-1,-1},{-1,-1,-1,-1,14,45,23,2},{30,33,-1,-1,-1,-1,31,-1},{17,49,-1,-1,-1,-1,-1,-1},{-1,56,12,47,-1,-1,-1,-1}};
    Solution S;
    cout << S.snakesAndLadders(board) << endl;
    return 0;
}