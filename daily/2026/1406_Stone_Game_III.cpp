#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int dp(vector<int>& stoneValue, vector<int>& memo, int n, int start, int turn){
        if (start >= n) return 0;
        if (memo[start] != INT_MIN) return memo[start];
        int res = stoneValue[start] - dp(stoneValue, memo, n, start + 1, turn ^ 1);
        if (start + 1 < n) res = max(res, stoneValue[start] + stoneValue[start + 1] - dp(stoneValue, memo, n, start + 2, turn ^ 1));
        if (start + 2 < n) res = max(res, stoneValue[start] + stoneValue[start + 1] + stoneValue[start + 2] - dp(stoneValue, memo, n, start + 3, turn ^ 1));
        return memo[start] = res;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> memo(n, INT_MIN);
        dp(stoneValue, memo, n, 0, 0);
        if (memo[0] == 0) return "Tie";
        return (memo[0] > 0)? "Alice" : "Bob";
    }
};

int main() {
    vector<int> stoneValue = {1,2,3,7};
    // vector<int> stoneValue = {1,2,3,-9};
    // vector<int> stoneValue = {1,2,3,6};
    Solution S;
    cout << S.stoneGameIII(stoneValue) << endl;
    return 0;
}
