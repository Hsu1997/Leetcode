#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> visited;

    int dfs(vector<vector<int>>& stones, int index){
        int ans = 0;
        visited[index] = true;
        for (int i = 0; i < stones.size(); i++){
            if (!visited[i] && (stones[index][0] == stones[i][0] || stones[index][1] == stones[i][1])){
                // cout << i << " ";
                ans += dfs(stones, i) + 1;
            }
        }
        return ans;;
    }

    int removeStones(vector<vector<int>>& stones) {
        visited = vector<bool>(stones.size(), false);
        int ans = 0;
        for (int i = 0; i < stones.size(); i++){
            if (!visited[i]) ans += dfs(stones, i);
        }
        return ans;
    }
};

int main(){
    // vector<vector<int>> stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    // vector<vector<int>> stones = {{0,0}};
    // vector<vector<int>> stones = {{0,0},{0,2},{1,1},{2,0},{2,2}};
    vector<vector<int>> stones = {{0,1},{4,7},{0,0},{6,7},{3,3},{7,4},{2,0},{3,6},{2,4}};
    Solution S;
    cout << S.removeStones(stones) << endl;
    return 0;
}