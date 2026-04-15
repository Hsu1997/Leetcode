#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size();
        int m = factory.size();
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<long long> prev(n, LLONG_MAX / 2);
        long long acc = 0;
        for (int cap = 0; cap < factory[0][1]; cap++){
            acc += abs(robot[cap] - factory[0][0]);
            prev[cap] = acc;
        }
        for (int f = 1; f < m; f++){
            vector<long long> curr = prev;
            int pos = factory[f][0];
            int limit = factory[f][1];
            for (int start = 0; start < n; start++){
                acc = 0;
                for (int cap = 0; cap < limit; cap++){
                    if (start + cap >= n) break;
                    acc += abs(robot[start + cap] - pos);
                    curr[start + cap] = min(curr[start + cap], ((start > 0)? prev[start - 1] : 0) + acc);
                }
            }
            prev = curr;
        }
        return prev.back();
    }
};

int main(){
    vector<int> robot = {0,4,6};
    vector<vector<int>> factory = {{2,2},{6,2}};
    // vector<int> robot = {1,-1};
    // vector<vector<int>> factory = {{-2,1},{2,1}};
    // vector<int> robot = {1,-1};
    // vector<vector<int>> factory = {{-2,1},{2,1},{3,0}};
    // vector<int> robot = {9,11,99,101};
    // vector<vector<int>> factory = {{10,1},{7,1},{14,1},{100,1},{96,1},{103,1}};
    Solution S;
    cout << S.minimumTotalDistance(robot, factory) << endl;
    return 0;
}