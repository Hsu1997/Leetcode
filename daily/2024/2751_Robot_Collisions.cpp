#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    struct Operation{
        bool operator()(const pair<pair<int,int>, pair<int,int>>&a, const pair<pair<int,int>, pair<int,int>>&b) const{
            return a.first.first < b.first.first;
        }
    };

    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        // {{pos,dir} {no., health}}
        vector<pair<pair<int,int>, pair<int,int>>> robots;
        // dir L(-1) R(1)
        for (int i = 0; i < positions.size(); i++) robots.push_back({{positions[i], (directions[i] == 'L')? -1 : 1}, {i, healths[i]}});
        // {no., health}
        sort(robots.begin(), robots.end(), Operation());
        // for (auto i : robots){
        //     cout << i.first.first << " " << i.first.second << ", " << i.second.first << " " << i.second.second << endl;
        // }
        // {no, health}
        stack<pair<int,int>> sta;
        vector<int> ans(positions.size(), -1);
        for (auto robot : robots){
            // cout << robot.first.first << " " << robot.first.second << ", " << robot.second.first << " " << robot.second.second << endl;
            int dir = robot.first.second;
            int no = robot.second.first;
            int health = robot.second.second;
            // ->
            if (dir == 1){
                sta.push({no, health});
            }
            // <-
            else{
                while(!sta.empty() && health > sta.top().second){
                    sta.pop();
                    health--;
                }
                if (sta.empty()){
                    ans[no] = health;
                }
                else{
                    if (sta.top().second == health) sta.pop();
                    else sta.top().second--;
                }
            }
        }
        while(!sta.empty()){
            auto robot = sta.top();
            sta.pop();
            ans[robot.first] = robot.second;
        }
        int servive = 0;
        for (int i = 0; i < ans.size(); i++){
            if (ans[i] != -1) ans[servive++] = ans[i];
        }
        return vector<int>(ans.begin(), ans.begin()+servive);
    }
};

int main(){
    vector<int> positions = {5,4,3,2,1};
    vector<int> healths = {2,17,9,15,10};
    string directions = "RRRRR";
    // vector<int> positions = {3,5,2,6};
    // vector<int> healths = {10,10,15,12};
    // string directions = "RLRL";
    // vector<int> positions = {1,2,5,6};
    // vector<int> healths = {10,10,11,11};
    // string directions = "RLRL";
    Solution S;
    vector<int> ans = S.survivedRobotsHealths(positions, healths, directions);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}