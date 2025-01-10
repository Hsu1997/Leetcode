#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int dp(int start_idx, vector<int>& days, vector<int>& costs, vector<int>& memo){
        if (start_idx >= memo.size()) return 0;
        if (memo[start_idx] != -1) return memo[start_idx];
        int start_day = days[start_idx];
        int next_idx_1 = upper_bound(days.begin(), days.end(), start_day) - days.begin();
        int next_idx_7 = upper_bound(days.begin(), days.end(), start_day+6) - days.begin();
        int next_idx_30 = upper_bound(days.begin(), days.end(), start_day+29) - days.begin();
        memo[start_idx] = min({
            costs[0] + dp(next_idx_1, days, costs, memo),
            costs[1] + dp(next_idx_7, days, costs, memo),
            costs[2] + dp(next_idx_30, days, costs, memo)
            });
        return memo[start_idx];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> memo(n, -1);
        return dp(0, days, costs, memo);
    }
};

int main(){
    vector<int> days = {1,4,6,7,8,20};
    vector<int> costs = {2,7,15};
    // vector<int> days = {1,2,3,4,5,6,7,8,9,10,30,31};
    // vector<int> costs = {2,7,15};
    Solution S;
    cout << S.mincostTickets(days, costs) << endl;
    return 0;
}