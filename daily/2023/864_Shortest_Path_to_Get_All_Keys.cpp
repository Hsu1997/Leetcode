#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    int m, n, start_x, start_y;
    vector<vector<char>> g;
    vector<int> d = {0, 1, 0, -1, 0};

    int graph(vector<string>& grid){
        m = grid.size();
        n = grid[0].length();
        g = vector<vector<char>>(m, vector<char>(n));
        int key = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                g[i][j] = grid[i][j];
                if (islower(g[i][j])) key++;
                if (g[i][j] == '@') start_x = i, start_y = j;
            }
        }
        return key;
    }

    bool inrange(int i, int j){
        return (i >= 0 && j >= 0 && i < m && j < n);
    }

    int shortestPathAllKeys(vector<string>& grid) {
        int key = graph(grid);
        vector<vector<vector<int>>> dp(1 << key, vector<vector<int>>(m, vector<int>(n, -1)));
        auto compare = [](const pair<int, pair<int, pair<int, int>>>& a, const pair<int, pair<int, pair<int, int>>>& b){
            return a.first > b.first;
        };
        // move, {key state, {i, j}}
        priority_queue<pair<int, pair<int, pair<int,int>>>, vector<pair<int, pair<int, pair<int,int>>>>, decltype(compare)> pq(compare);
        pq.push({0, {0, {start_x, start_y}}});
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            int path = temp.first;
            int key_state = temp.second.first;
            int x = temp.second.second.first;
            int y = temp.second.second.second;
            // bitset<6> binary(key_state);
            // cout << "{" << x << ", " << y << "}, key state = " <<  binary << ", path = " << path << endl;
            if (key_state == (1 << key) - 1) return path;
            for (int k = 0; k < 4; k++){
                int new_x = x + d[k];
                int new_y = y + d[k+1];
                if (!inrange(new_x, new_y) || g[new_x][new_y] == '#') continue;
                if (isalpha(g[new_x][new_y])){
                    // key or lock
                    if (islower(g[new_x][new_y])){
                        // key
                        int new_key_state = (1 << (g[new_x][new_y] - 'a')) | key_state;
                        if (dp[new_key_state][new_x][new_y] == -1 || path + 1 < dp[new_key_state][new_x][new_y]){
                            dp[new_key_state][new_x][new_y] = path + 1;
                            pq.push({path + 1, {new_key_state, {new_x, new_y}}});
                        }
                    }
                    else{
                        // lock
                        if (((1 << (g[new_x][new_y] - 'A')) & key_state) == 0) continue;
                        else{
                            // just like a normal path
                            if (dp[key_state][new_x][new_y] == -1 || path + 1 < dp[key_state][new_x][new_y]){
                                dp[key_state][new_x][new_y] = path + 1;
                                pq.push({path + 1, {key_state, {new_x, new_y}}});
                            }
                        }
                    }
                }
                else{
                    // normal path
                    if (dp[key_state][new_x][new_y] == -1 || path + 1 < dp[key_state][new_x][new_y]){
                        dp[key_state][new_x][new_y] = path + 1;
                        pq.push({path + 1, {key_state, {new_x, new_y}}});
                    }
                }
            }
        }
        
        return -1;
    }
};

int main(){
    // vector<string> grid = {"@.a..","###.#","b.A.B"};
    // vector<string> grid = {"@..aA","..B#.","....b"};
    vector<string> grid = {"@Aa"};
    Solution S;
    cout << S.shortestPathAllKeys(grid) << endl;
    return 0;
}