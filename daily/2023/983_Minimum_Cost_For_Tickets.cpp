#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> s;
        for (auto i : days) s.insert(i);
        vector<int> dp(366);
        for (int i = 1; i < 366; i++){
            dp[i] = dp[i-1];
            if (!s.count(i)) continue;
            dp[i] = min({dp[i-1] + costs[0], dp[max(0,i-7)] + costs[1], dp[max(0,i-30)] + costs[2]});
        }
        return dp[365];
    }
};

int main(){
    Solution S;
    // vector<int> days = {1,4,6,7,8,20};
    vector<int> days = {1,2,3,4,5,6,7,8,9,10,30,31};
    vector<int> costs = {2,7,15};
    cout << S.mincostTickets(days, costs) << endl;
    return 0;
}