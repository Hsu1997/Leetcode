#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> blue_state(n,INT_MAX);
        vector<int> red_state(n,INT_MAX);
        vector<vector<int>> red_path(n);
        vector<vector<int>> blue_path(n);
        for (auto i : redEdges) red_path[i[0]].push_back(i[1]);
        // for (auto i : red_path){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }
        for (auto i : blueEdges) blue_path[i[0]].push_back(i[1]);
        // for (auto i : blue_path){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }
        vector<bool> visited_r(n,false);
        vector<bool> visited_b(n,false);
        // red : 1, blue : -1
        // red first
        visited_r[0] = true;
        visited_b[0] = true;
        int path = 0;
        int color = 1;
        queue<int> que;
        que.push(0);
        while(!que.empty()){
            path++;
            int s = que.size();
            while(s--){
                int temp = que.front();
                que.pop();
                // cout << "now at node " << temp << ", ";
                if (color == 1){
                    // cout << "looking for red path : " << endl;
                    for (int neighbor : red_path[temp]){
                        if (!visited_r[neighbor]){
                            // cout << neighbor << " ";
                            red_state[neighbor] = path;
                            visited_r[neighbor] = true;
                            que.push(neighbor);
                        }
                    }
                }
                else if (color == -1){
                    // cout << "looking for blue path : " << endl;
                    for (int neighbor : blue_path[temp]){
                        if (!visited_b[neighbor]){
                            // cout << neighbor << " ";
                            blue_state[neighbor] = path;
                            visited_b[neighbor] = true;
                            que.push(neighbor);
                        }
                    }
                }
                else cout << "error" << endl;
                // cout << endl;
            }
            color *= -1;
        }
        // for (auto i : red_state) cout << i << " ";
        // cout << endl;
        // for (auto i : blue_state) cout << i << " ";
        // cout << endl;

        // blue first
        visited_r = vector<bool>(n,false);
        visited_b = vector<bool>(n,false);
        visited_r[0] = true;
        visited_b[0] = true;
        path = 0;
        color = -1;
        que.push(0);
        while(!que.empty()){
            path++;
            int s = que.size();
            while(s--){
                int temp = que.front();
                que.pop();
                if (color == 1){
                    for (int neighbor : red_path[temp]){
                        if (!visited_r[neighbor]){
                            red_state[neighbor] = min(red_state[neighbor],path);
                            visited_r[neighbor] = true;
                            que.push(neighbor);
                        }
                    }
                }
                else{
                    for (int neighbor : blue_path[temp]){
                        if (!visited_b[neighbor]){
                            blue_state[neighbor] = min(blue_state[neighbor],path);
                            visited_b[neighbor] = true;
                            que.push(neighbor);
                        }
                    }
                }
            }
            color *= -1;
        }
        // for (auto i : red_state) cout << i << " ";
        // cout << endl;
        // for (auto i : blue_state) cout << i << " ";
        // cout << endl;
        
        vector<int> ans(n,INT_MAX);
        ans[0] = 0;
        for (int i = 1; i < n; i++){
            // cout << i << " : " << red_state[i] << ", " << blue_state[i];
            ans[i] = min(red_state[i], blue_state[i]);
            if (ans[i] == INT_MAX) ans[i] = -1;
            // cout << ", ans = " << ans[i] << endl;
        }

        return ans;
    }
};

int main(){
    int n = 3;
    vector<vector<int>> redEdges = {{0,1},{1,2}};
    vector<vector<int>> blueEdges = {};
    // int n = 3;
    // vector<vector<int>> redEdges = {{0,1}};
    // vector<vector<int>> blueEdges = {{2,1}};
    Solution S;
    vector<int> ans = S.shortestAlternatingPaths(n,redEdges,blueEdges);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}