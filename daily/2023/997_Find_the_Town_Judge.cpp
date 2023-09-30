#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n == 1 && trust.empty()) return 1;
        unordered_set<int> have_trust;
        unordered_map<int, unordered_set<int>> m;
        for (auto i : trust){
            m[i[1]].insert(i[0]);
            have_trust.insert(i[0]);
        }
        for (auto i : m){
            if (m[i.first].size() == n-1 && have_trust.count(i.first) == 0) return i.first;
        }
        return -1;
    }
};

int main(){
    // int n = 2;
    // vector<vector<int>> trust = {{1,2}};
    // int n = 3;
    // vector<vector<int>> trust = {{1,3},{2,3}};
    // int n = 3;
    // vector<vector<int>> trust = {{1,3},{2,3},{3,1}};
    int n = 1;
    vector<vector<int>> trust = {};
    Solution S;
    cout << S.findJudge(n, trust) << endl;
    return 0;
}