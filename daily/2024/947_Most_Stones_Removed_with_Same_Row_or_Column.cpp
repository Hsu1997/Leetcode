#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < n; i++){
            int row = stones[i][0];
            int col = stones[i][1];
            m[row].push_back(i);
            m[-col-1].push_back(i);
        }
        // for (auto i : m){
        //     cout << i.first << " : ";
        //     for (auto j : i.second) cout << j << " ";
        //     cout << endl;
        // }
        vector<bool> visited(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++){
            if (!visited[i]){
                int temp_ans = 0;
                queue<int> que;
                que.push(i);
                visited[i] = true;
                while(!que.empty()){
                    int temp_stone = que.front();
                    que.pop();
                    temp_ans++;
                    int temp_row = stones[temp_stone][0];
                    int temp_col = stones[temp_stone][1];
                    // cout << temp_stone << " (" << temp_row << ", " << temp_col << ") ";
                    for (auto i : m[temp_row]) if (!visited[i]) que.push(i), visited[i] = true;
                    for (auto i : m[-temp_col - 1]) if (!visited[i]) que.push(i), visited[i] = true;
                }
                // cout << endl << "temp ans = " << temp_ans << endl;
                ans += temp_ans - 1;
            }
        }
        return ans;
    }
};

int main(){
    // vector<vector<int>> stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    // vector<vector<int>> stones = {{0,0},{0,2},{1,1},{2,0},{2,2}};
    vector<vector<int>> stones = {{0,0}};
    Solution S;
    cout << S.removeStones(stones) << endl;
    return 0;
}