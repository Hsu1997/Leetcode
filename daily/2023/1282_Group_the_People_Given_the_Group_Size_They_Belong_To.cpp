#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        unordered_map<int,vector<int>> m;
        for (int i = 0; i < n; i++) m[groupSizes[i]].push_back(i);
        vector<vector<int>> ans;
        for (auto i : m){
            int s = i.first;
            vector<int> temp;
            for (auto j : i.second){
                temp.push_back(j);
                if (temp.size() == s) ans.push_back(temp), temp.clear();
            }
        }
        return ans;
    }
};

int main(){
    // vector<int> groupSizes = {3,3,3,3,3,1,3};
    vector<int> groupSizes = {2,1,3,3,3,2};
    Solution S;
    vector<vector<int>> ans = S.groupThePeople(groupSizes);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}