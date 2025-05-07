#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int n, m;
    bool in_range(int i, int j){
        return i >= 0 && j >= 0 && i < m && j < n;
    }
    int minTimeToReach(vector<vector<int>>& moveTime) {
        m = moveTime.size();
        n = moveTime[0].size();
        vector<int> d = {0, 1, 0, -1, 0};
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0, {0, 0}});
        vector<vector<int>> ans(m, vector<int>(n, -1));
        while(!pq.empty()){
            auto [t, pos] = pq.top();
            auto [x, y] = pos;
            pq.pop();
            for (int dir = 0; dir < 4; dir++){
                int i = x + d[dir];
                int j = y + d[dir+1];
                if (in_range(i, j) && ans[i][j] == -1){
                    ans[i][j] = max(t, moveTime[i][j]) + 1;
                    pq.push({ans[i][j], {i, j}});
                }
            }
        }
        return ans[m-1][n-1];
    }
};

int main(){
    vector<vector<int>> moveTime = {{0,4},{4,4}};
    // vector<vector<int>> moveTime = {{0,0,0},{0,0,0}};
    // vector<vector<int>> moveTime = {{0,1},{1,2}};
    Solution S;
    cout << S.minTimeToReach(moveTime) << endl;
    return 0;
}