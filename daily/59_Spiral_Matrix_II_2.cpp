#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> xd = {0,1,0,-1};
        vector<int> yd = {1,0,-1,0};
        vector<vector<int>> ans(n, vector<int>(n));
        int count = 2;
        int x = 0;
        int y = 0;
        int d = 0;
        ans[0][0] = 1;
        while(count <= n * n){
            if (x+xd[d] >= n || x+xd[d] < 0 || y+yd[d] >= n || y+yd[d] < 0 || ans[x+xd[d]][y+yd[d]] != 0) d = (d+1)%4;
            else{
                x += xd[d];
                y += yd[d];
                ans[x][y] = count++;
            }
        }
        return ans;
    }
};

int main(){
    int n = 5;
    Solution S;
    vector<vector<int>> ans = S.generateMatrix(n);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}