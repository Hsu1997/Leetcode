#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int n;
    int ans = 0;
    vector<vector<int>> bombs;

    long caldis(int a, int b){
        return (long)(bombs[a][0]-bombs[b][0]) * (long)(bombs[a][0]-bombs[b][0]) + (long)(bombs[a][1]-bombs[b][1]) * (long)(bombs[a][1]-bombs[b][1]);
    }

    int start(int i){
        vector<bool> visited(n, false);
        int ans = 0;
        queue<int> que;

        que.push(i);
        visited[i] = true;

        while(!que.empty()){
            int temp = que.front();
            que.pop();
            ans++;
            for (int k = 0; k < n; k++){
                if (caldis(k, temp) <= (long)bombs[temp][2] * (long)bombs[temp][2] && !visited[k]){
                    que.push(k);
                    visited[k] = true;
                }
            }
        }
        return ans;
    }

    int maximumDetonation(vector<vector<int>>& _bombs) {
        bombs = _bombs;
        n = bombs.size();
        for (int i = 0; i < n; i++) ans = max(ans, start(i));
        return ans;
    }
};

int main(){
    vector<vector<int>> bombs = {{2,1,3},{6,1,4}};
    // vector<vector<int>> bombs = {{1,2,3},{2,3,1},{3,4,2},{4,5,3},{5,6,4}};
    Solution S;
    cout << S.maximumDetonation(bombs) << endl;
    return 0;
}