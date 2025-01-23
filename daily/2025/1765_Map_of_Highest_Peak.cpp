#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int m, n;
    bool in_range(int i, int j) {return i >= 0 && i < m && j >= 0 && j < n;}
    vector<int> dir = {0, 1, 0, -1, 0};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        m = isWater.size();
        n = isWater[0].size();
        queue<pair<int,int>> que;
        vector<vector<int>> ans(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (isWater[i][j]){
                    ans[i][j] = 0;
                    que.push({i,j});
                }
            }
        }
        int height = 1;
        while(!que.empty()){
            int s = que.size();
            while(s--){
                auto [i, j] = que.front();
                que.pop();
                for (int d = 0; d < 4; d++){
                    int x = i + dir[d];
                    int y = j + dir[d+1];
                    if (in_range(x, y) && ans[x][y] == -1){
                        ans[x][y] = height;
                        que.push({x, y});
                    }
                }
            }
            height++;
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> isWater = {{0,1},{0,0}};
    // vector<vector<int>> isWater = {{0,0,1},{1,0,0},{0,0,0}};
    Solution S;
    vector<vector<int>> ans = S.highestPeak(isWater);
    for (auto i : ans){
        for (int j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}