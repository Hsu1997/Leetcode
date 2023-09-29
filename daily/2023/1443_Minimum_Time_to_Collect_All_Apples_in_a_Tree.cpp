#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int apple = 0;
    int acc_apple = 0;
    int ans = 0;
    vector<bool> visited;
    vector<bool> hasApple;
    vector<vector<int>> edge;

    void dfs(int start){
        // cout << "dfs to " << start << " : step = " << ans << ", apple = " << acc_apple << endl;
        if (hasApple[start]){
            // cout << "find apple at node " << start << endl; 
            acc_apple++, hasApple[start] = false;
        }
        for (auto i : edge[start]){
            int temp = acc_apple;
            if (!visited[i]){
                // cout << "next move to " << i << endl;
                visited[i] = true;
                ans++;
                dfs(i);
                ans++;
                // cout << "return to " << start << ", now step is " << ans << ", temp = " << temp << ", finded apple = " << acc_apple << endl;
                if (temp == acc_apple){
                    ans -= 2;
                    // cout << "not find apple, step minus 2, now step is " << ans << endl;
                }
                visited[i] = false;
                // cout << i << " : " << ans << endl;
            }
        }
        return;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& _hasApple) {
        hasApple = _hasApple;
        for (auto i : hasApple) if(i) apple++;
        if (apple == 0) return 0;
        visited = vector<bool>(n, false);
        edge = vector<vector<int>>(n, vector<int>());
        for (auto i : edges){
            edge[i[0]].push_back(i[1]);
            edge[i[1]].push_back(i[0]);
        }
        // int z = 0;
        // for (auto i : edge){
        //     cout << z++ << " : ";
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }
        visited[0] = true;
        dfs(0);
        return ans;
    }
};

int main(){
    int n = 7;
    vector<vector<int>> edges = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
    vector<bool> hasApple = {0,0,1,0,1,1,0};
    // vector<bool> hasApple = {0,0,1,0,0,1,0};
    // vector<bool> hasApple = {0,0,0,0,0,0,0};

    Solution S;
    cout << S.minTime(n, edges, hasApple) << endl;
    return 0;
}