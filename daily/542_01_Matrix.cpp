#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> xd = {-1,0,1,0};
    vector<int> yd = {0,1,0,-1};
    int m;
    int n;

    bool in_board(int x, int y){
        return (x >= 0) && (x < m) && (y >= 0) && (y < n);
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int,int>> que;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (mat[i][j] == 0){
                    que.push({i,j});
                    ans[i][j] = 0;
                }
            }
        }
        int epoch = 1;
        while(!que.empty()){
            int k = que.size();
            while(k--){
                int x = que.front().first;
                int y = que.front().second;
                que.pop();
                for (int d = 0; d < 4; d++){
                    if (in_board(x+xd[d], y+yd[d]) && ans[x+xd[d]][y+yd[d]] == -1){
                        ans[x+xd[d]][y+yd[d]] = epoch;
                        que.push({x+xd[d], y+yd[d]});
                    }
                }
            }
            epoch++;
        }
        return ans;
    }
};

int main(){
    // vector<vector<int>> mat = {{0,0,0},{0,1,0},{0,0,0}};
    vector<vector<int>> mat = {{0,0,0},{0,1,0},{1,1,1}};
    Solution S;
    vector<vector<int>> ans = S.updateMatrix(mat);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}