#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        int m = walls.size();
        vector<pair<int,int>> robot;
        for (int i = 0; i < n; i++) robot.push_back({robots[i], distance[i]});
        sort(walls.begin(), walls.end());
        sort(robot.begin(), robot.end());
        vector<vector<int>> dp(n, vector<int>(2, 0));

        auto loweridx = [&](int x){
            return (int)(lower_bound(walls.begin(), walls.end(), x) - walls.begin());
        };
        auto upperidx = [&](int x){
            return (int)(upper_bound(walls.begin(), walls.end(), x) - walls.begin());
        };

        dp[0][0] = upperidx(robot[0].first) - loweridx(robot[0].first - robot[0].second);
        if (n < 2) dp[0][1] = upperidx(robot[0].first + robot[0].second) - loweridx(robot[0].first);
        else{
            if (robot[0].first + robot[0].second < robot[1].first){
                dp[0][1] = upperidx(robot[0].first + robot[0].second) - loweridx(robot[0].first);
            }
            else{
                dp[0][1] = loweridx(robot[1].first) - loweridx(robot[0].first);
            }
        }

        for (int i = 1; i < n; i++){
            int currPos = robot[i].first;
            int currd = robot[i].second;
            int prevPos = robot[i-1].first;
            int prevd = robot[i-1].second;
            // shooting left :
            // prev left : (prevPos, pos] / [pos - d, pos] 
            int l = max(currPos - currd, prevPos + 1);
            dp[i][0] = dp[i-1][0] + (upperidx(currPos) - loweridx(l));
            // prev right : (prevPos + prevd, pos] /  [pos - d, pos]
            if (prevPos + prevd < currPos - currd){
                dp[i][0] = max(dp[i][0], dp[i-1][1] + upperidx(currPos) - loweridx(currPos - currd));
            }
            else{
                l = min(prevPos + prevd + 1, currPos);
                dp[i][0] = max(dp[i][0], dp[i-1][1] + upperidx(currPos) - loweridx(l));
            }

            // shooting right :
            int RightLimit = currPos + currd;
            if (i < n - 1){
                RightLimit = min(RightLimit, robot[i+1].first - 1);
            }
            // prev left : [pos, RightLimit]
            // prev right : [pos, RightLimit]
            dp[i][1] = max(dp[i-1][0], dp[i-1][1]) + upperidx(RightLimit) - loweridx(currPos);
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
};

int main(){
    // vector<int> robots = {4};
    // vector<int> distance = {3};
    // vector<int> walls = {1,10};
    // vector<int> robots = {10,2};
    // vector<int> distance = {5,1};
    // vector<int> walls = {5,2,7};
    // vector<int> robots = {1,2};
    // vector<int> distance = {100,1};
    // vector<int> walls = {10};
    vector<int> robots = {12,6,34,28,58,10,42,4,55,48,3,7,26,40,54,17,32,23,56,43,31,1,24};
    vector<int> distance = {2,5,1,6,3,8,6,4,5,6,9,3,3,8,6,3,5,7,5,7,5,7,7};
    vector<int> walls = {25,37,48,94,56,55,30,28,40,35,15,97,12,6,85,14,52,60,27,71,5,19,73,9,92,32,11,63,13,8,39,88,44,79,7,17,78,93,33,80,26,46,68,47,95,24,36,49,90,70,64,18,57,50,66,51,54,2,21,86,16,61,91,75,58,38,65,45,29,69,3,53,1,87,83,59,23,10,62,76,43,96,77,31,4,34,42,67,89,41,82,72,22,20,81,84,74};
    Solution S;
    cout << S.maxWalls(robots, distance, walls) << endl;
    return 0;
}