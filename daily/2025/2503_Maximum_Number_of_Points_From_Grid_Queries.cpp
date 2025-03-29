#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int m, n;
    vector<int> d = {0, 1, 0, -1, 0};

    bool inrange(int i, int j){
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        m = grid.size();
        n = grid[0].size();
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i : queries) q.push(i);
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        unordered_map<int,int> c;
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;
        int count = 0;
        while(!q.empty()){
            int curr = q.top();
            q.pop();
            while(!pq.empty() && pq.top().first < curr){
                auto [val, pos] = pq.top();
                pq.pop();
                count++;
                for (int dir = 0; dir < 4; dir++){
                    int x = pos.first + d[dir];
                    int y = pos.second + d[dir+1];
                    if (!inrange(x, y) || visited[x][y]) continue;
                    pq.push({grid[x][y], {x, y}});
                    visited[x][y] = true;
                }
            }
            c[curr] = count;
        }
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) ans[i] = c[queries[i]];
        return ans;
    }
};

int main(){
    vector<vector<int>> grid = {{1,2,3},{2,5,7},{3,5,1}};
    vector<int> queries = {5,6,2};
    // vector<vector<int>> grid = {{5,2,1},{1,1,2}};
    // vector<int> queries = {3};
    Solution S;
    vector<int> ans = S.maxPoints(grid, queries);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}