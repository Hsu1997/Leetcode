#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size() + 1;
        vector<int> ans;
        unordered_map<int,vector<int>> m;
        unordered_set<int> visited;
        for (auto i : adjacentPairs){
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
        }
        for (auto i : m){
            if (i.second.size() == 1){
                ans.push_back(i.first);
                visited.insert(i.first);
                break;
            }
        }
        while(ans.size() < n){
            vector<int>& temp = m[ans.back()];
            for (int i : temp){
                if (visited.find(i) == visited.end()){
                    ans.push_back(i);
                    visited.insert(i);
                    // cout << i << " ";
                    break;
                }
            }
        }
        return ans;
    }
};

int main(){
    // vector<vector<int>> adjacentPairs = {{2,1},{3,4},{3,2}};
    vector<vector<int>> adjacentPairs = {{4,-2},{1,4},{-3,1}};
    Solution S;
    vector<int> ans = S.restoreArray(adjacentPairs);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}