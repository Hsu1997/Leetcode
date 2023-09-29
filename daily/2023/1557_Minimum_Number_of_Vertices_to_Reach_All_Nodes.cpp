#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_set<int> s;
        for (int i = 0; i < n; i++) s.insert(i);
        for (auto i : edges) s.erase(i[1]);
        vector<int> ans(s.begin(), s.end());
        return ans;
    }
};

int main(){
    int n = 6;
    vector<vector<int>> edges = {{0,1},{0,2},{2,5},{3,4},{4,2}};
    Solution S;
    vector<int> ans = S.findSmallestSetOfVertices(n, edges);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}