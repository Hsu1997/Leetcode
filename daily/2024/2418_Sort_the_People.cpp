#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<int> index(names.size());
        iota(index.begin(), index.end(), 0);
        sort(index.begin(), index.end(), [&](int a, int b){return heights[a] > heights[b];});
        vector<string> ans;
        for (int i : index) ans.push_back(names[i]);
        return ans;
    }
};

int main(){
    vector<string> names = {"Mary","John","Emma"};
    vector<int> heights = {180,165,170};
    // vector<string> names = {"Alice","Bob","Bob"};
    // vector<int> heights = {155,185,150};
    Solution S;
    vector<string> ans = S.sortPeople(names, heights);
    for (auto i : ans) cout << i << " ";
    cout << endl;
}