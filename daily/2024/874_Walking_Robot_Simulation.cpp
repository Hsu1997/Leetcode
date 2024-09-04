#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    struct pair_hash{
        template <class T1, class T2>
        size_t operator()(const pair<T1,T2>& a) const{
            int h1 = hash<T1>{}(a.first);
            int h2 = hash<T2>{}(a.second);
            return h1 ^ h2;
        }
    };
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int ans = 0;
        unordered_set<pair<int,int>, pair_hash> s;
        for (auto& obstacle : obstacles){
            s.insert({obstacle[0], obstacle[1]});
        }
        int x = 0;
        int y = 0;
        int dir = 0;
        vector<pair<int,int>> d = {{0,1},{1,0},{0,-1},{-1,0}};
        for (int command : commands){
            if (command == -1) dir = (dir + 1) % 4;
            else if (command == -2) dir = (dir + 4 - 1) % 4;
            else{
                for (int k = 0; k < command; k++){
                    int nx = x + d[dir].first;
                    int ny = y + d[dir].second;
                    if (s.find({nx, ny}) != s.end()) continue;
                    x = nx, y = ny;
                    ans = max(ans, x * x + y * y);
                }
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
    // vector<vector<int>> obstacles = {};
    Solution S;
    cout << S.robotSim(commands, obstacles) << endl;
    return 0;
}