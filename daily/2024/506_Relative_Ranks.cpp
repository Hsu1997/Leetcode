#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans = {};
        vector<int> sorted = score;
        sort(sorted.begin(), sorted.end(), greater<int>());
        // for (int i : sorted) cout << i << " ";
        // cout << endl;
        for (int i : score) ans.push_back(to_string(lower_bound(sorted.begin(), sorted.end(), i, greater<int>()) - sorted.begin() + 1));
        for (int i = 0; i < ans.size(); i++){
            if (ans[i] == "1") ans[i] = "Gold Medal";
            else if (ans[i] == "2") ans[i] = "Silver Medal";
            else if (ans[i] == "3") ans[i] = "Bronze Medal";
        }
        return ans;
    }
};

int main(){
    vector<int> score = {5,4,3,2,1};
    // vector<int> score = {10,3,8,9,4};
    Solution S;
    vector<string> ans = S.findRelativeRanks(score);
    for (string i : ans) cout << i << " ";
    cout << endl;
    return 0;
}