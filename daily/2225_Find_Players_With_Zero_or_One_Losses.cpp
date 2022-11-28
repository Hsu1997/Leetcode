#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,pair<int,int>> m;
        for (auto i : matches){
            m[i[0]].first++;
            m[i[1]].second++;
        }
        vector<vector<int>> ans(2,vector<int>(0));
        for (auto i : m){
            if (i.second.second == 0) ans[0].push_back(i.first);
            if (i.second.second == 1) ans[1].push_back(i.first);
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> matches = {{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}};
    // vector<vector<int>> matches = {{2,3},{1,3},{5,4},{6,4}};
    Solution S;
    vector<vector<int>> ans = S.findWinners(matches);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}