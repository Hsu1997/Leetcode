#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int n;
    int kx;
    int ky;
    vector<vector<vector<int>>> dp;
    unordered_map<int,int> chess_on_board;
    vector<vector<int>> dir = {{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2}};
    vector<vector<int>> pairs_distance;
    int pos_to_index(int i, int j) {return i * 50 + j;}
    bool in_board(int i, int j) {return i >= 0 && i < 50 && j >= 0 && j < 50;}

    void make_pairs_distance(vector<vector<int>>& positions){
        pairs_distance = vector<vector<int>>(n + 1, vector<int>(n + 1));
        for (int i = 0; i <= n; i++){
            vector<vector<bool>> visited(50, vector<bool>(50, false));
            int visited_chess = 0;
            queue<pair<int,int>> que;
            int x = (i == n)? kx : positions[i][0];
            int y = (i == n)? ky : positions[i][1];
            visited[x][y] = true;
            que.push({x, y});
            pairs_distance[i][i] = 0;
            int steps = 0;
            while(!que.empty() && visited_chess < n){
                steps++;
                int k = que.size();
                while(k--){
                    auto [tx, ty] = que.front();
                    que.pop();
                    for (auto& d : dir){
                        int nx = tx + d[0];
                        int ny = ty + d[1];
                        if (!in_board(nx, ny) || visited[nx][ny]) continue;
                        visited[nx][ny] = true;
                        if (chess_on_board.find(pos_to_index(nx, ny)) != chess_on_board.end()){
                            int chess_index = chess_on_board[pos_to_index(nx, ny)];
                            visited_chess++;
                            pairs_distance[i][chess_index] = steps;
                            pairs_distance[chess_index][i] = steps;
                        }
                        que.push({nx, ny});
                    }
                }
            }
        }
        // for (auto i : pairs_distance){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }
        return;
    }

    int helper(int who, int starting_index, int now_chess_status){
        if (now_chess_status == 0) return 0;
        if (dp[who][starting_index][now_chess_status] != -1) return dp[who][starting_index][now_chess_status];
        int temp_ans = (who)? 1e8 : 0;
        for (int i = 0; i < n; i++){
            if ((now_chess_status & (1 << i)) == 0) continue;
            if (who == 0) temp_ans = max(temp_ans, pairs_distance[starting_index][i] + helper(1, i, now_chess_status ^ (1 << i)));
            else temp_ans = min(temp_ans, pairs_distance[starting_index][i] + helper(0, i, now_chess_status ^ (1 << i)));
        }
        return dp[who][starting_index][now_chess_status] = temp_ans;
    }

    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        this->kx = kx;
        this->ky = ky;
        n = positions.size();
        dp = vector<vector<vector<int>>>(2, vector<vector<int>>(n + 1, vector<int>(1 << n, -1)));
        for (int i = 0; i < n; i++) chess_on_board[pos_to_index(positions[i][0], positions[i][1])] = i;
        int stituation = (1 << n) - 1;
        make_pairs_distance(positions);
        return helper(0, n, stituation);
        return dp[0][n][stituation];
    }
};

int main(){
    // int kx = 1;
    // int ky = 1;
    // vector<vector<int>> positions = {{0,0}};
    // int kx = 0;
    // int ky = 2;
    // vector<vector<int>> positions = {{1,1},{2,2},{3,3}};
    // int kx = 0;
    // int ky = 0;
    // vector<vector<int>> positions = {{1,2},{2,4}};
    int kx = 3;
    int ky = 2;
    vector<vector<int>> positions = {{9,10},{0,4},{1,1},{7,8},{2,5},{6,10},{1,4},{7,1}};
    Solution S;
    cout << S.maxMoves(kx, ky, positions) << endl;
    return 0;
}