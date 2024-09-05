#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int total = mean * (m + n);
        int observation_total = 0;
        for (int i : rolls) observation_total += i;
        int missing_total = total - observation_total;
        if (missing_total < n || missing_total > n * 6) return {};
        vector<int> ans(n, missing_total / n);
        for (int i = 0; i < missing_total % n; i++) ans[i]++;
        return ans;
    }
};

int main(){
    vector<int> rolls = {3,2,4,3};
    int mean = 4;
    int n = 2;
    // vector<int> rolls = {1,5,6};
    // int mean = 3;
    // int n = 4;
    // vector<int> rolls = {1,2,3,4};
    // int mean = 6;
    // int n = 4;
    Solution S;
    vector<int> ans = S.missingRolls(rolls, mean, n);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}