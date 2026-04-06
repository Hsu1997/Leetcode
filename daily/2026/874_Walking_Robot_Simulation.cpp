#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // {up, right, down, left}
        int dir = 0;
        int ans = 0;
        unordered_map<int, vector<int>> obstacles_x;
        unordered_map<int, vector<int>> obstacles_y;
        int currx = 0;
        int curry = 0;
        for (vector<int>& obstacle : obstacles){
            int x = obstacle[0];
            int y = obstacle[1];
            obstacles_x[x].push_back(y);
            obstacles_y[y].push_back(x);
        }
        for (auto& [idx, v] : obstacles_x) sort(v.begin(), v.end());
        for (auto& [idx, v] : obstacles_y) sort(v.begin(), v.end());

        for (int command : commands){
            if (command < 0){
                if (command == -1) dir = (dir + 1) % 4;
                else dir = (dir + 3) % 4;
            }
            else{
                if (dir % 2 == 0){
                    // up or down
                    if (dir == 0){
                        int idx = upper_bound(obstacles_x[currx].begin(), obstacles_x[currx].end(), curry) - obstacles_x[currx].begin();
                        if (idx >= obstacles_x[currx].size() || curry + command < obstacles_x[currx][idx]) curry += command;
                        else curry = obstacles_x[currx][idx] - 1;
                    }
                    else{
                        int idx = lower_bound(obstacles_x[currx].begin(), obstacles_x[currx].end(), curry) - obstacles_x[currx].begin();
                        idx--;
                        if (idx < 0 || curry - command > obstacles_x[currx][idx]) curry -= command;
                        else curry = obstacles_x[currx][idx] + 1;
                    }
                }
                else{
                    // left or right
                    if (dir == 1){
                        int idx = upper_bound(obstacles_y[curry].begin(), obstacles_y[curry].end(), currx) - obstacles_y[curry].begin();
                        if (idx >= obstacles_y[curry].size() || currx + command < obstacles_y[curry][idx]) currx += command;
                        else currx = obstacles_y[curry][idx] - 1;
                    }
                    else{
                        int idx = lower_bound(obstacles_y[curry].begin(), obstacles_y[curry].end(), currx) - obstacles_y[curry].begin();
                        idx--;
                        if (idx < 0 || currx - command > obstacles_y[curry][idx]) currx -= command;
                        else currx = obstacles_y[curry][idx] + 1;
                    }
                }
                ans = max(ans, currx * currx + curry * curry);
            }
        }
        return ans;
    }
};

int main(){
    vector<int> commands = {4,-1,3};
    vector<vector<int>> obstacles = {};
    // vector<int> commands = {4,-1,4,-2,4};
    // vector<vector<int>> obstacles = {{2,4}};
    // vector<int> commands = {6,-1,-1,6};
    // vector<vector<int>> obstacles = {{0,0}};
    Solution S;
    cout << S.robotSim(commands, obstacles) << endl;
    return 0;
}