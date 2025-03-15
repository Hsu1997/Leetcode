#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool in_range(int i, int j, int m, int n){
        return i >= 0 && j >= 0 && i < m && j < n;
    };
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        int water = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<int> d = {0, 1, 0, -1, 0};
        auto compare = [](const pair<int,pair<int,int>>& a, const pair<int,pair<int,int>>& b){
            return a.first > b.first;
        };
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, decltype(compare)> pq(compare);
        for (int i = 0; i < m; i++){
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][n-1], {i, n-1}});
            visited[i][0] = true;
            visited[i][n-1] = true;
        }
        for (int j = 1; j < n-1; j++){
            pq.push({heightMap[0][j], {0, j}});
            pq.push({heightMap[m-1][j], {m-1, j}});
            visited[0][j] = true;
            visited[m-1][j] = true;
        }
        while(!pq.empty()){
            auto [height, pos] = pq.top();
            auto [i, j] = pos;
            pq.pop();
            for (int dir = 0; dir < 4; dir++){
                int r = i + d[dir];
                int c = j + d[dir+1];
                if (in_range(r, c, m, n) && !visited[r][c]){
                    int neighbor_height = heightMap[r][c];
                    if (neighbor_height < height) water += height - neighbor_height;
                    visited[r][c] = true;
                    pq.push({max(height, neighbor_height), {r, c}});
                }
            }
        }
        return water;
    }
};

int main(){
    // vector<vector<int>> heightMap = {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
    vector<vector<int>> heightMap = {{3,3,3,3,3},{3,2,2,2,3},{3,2,1,2,3},{3,2,2,2,3},{3,3,3,3,3}};
    Solution S;
    cout << S.trapRainWater(heightMap) << endl;
    return 0;
}