#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    struct event{
        int start;
        int end;
        int profit;
    };

    static bool my_compare(event a, event b){
        return (a.start != b.start)? a.start < b.start : (a.end != b.end)? a.end < b.end : a.profit > b.profit;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<event> e;
        for (int i = 0; i < n; i++) e.push_back({startTime[i], endTime[i], profit[i]});
        sort(e.begin(), e.end(), my_compare);
        // for (auto i : e){
        //     cout << i.start << " " << i.end << " " << i.profit << endl;
        // }
        
        for (int i = 0; i < n; i++){
            startTime[i] = e[i].start;
            endTime[i] = e[i].end;
            profit[i] = e[i].profit;
        }
        vector<int> dp(n, 0);
        dp[n-1] = profit[n-1];
        for (int i = n-2; i >= 0; i--){
            if (endTime[i] > startTime[n-1]) dp[i] = max(dp[i+1], profit[i]);
            else{
                dp[i] = max(dp[i+1], profit[i] + dp[lower_bound(startTime.begin(), startTime.end(), endTime[i]) - startTime.begin()]);
            }
        }
        for (auto i : dp) cout << i << " ";
        cout << endl;
        return dp[0];
    }
};

int main(){
    vector<int> startTime = {1,2,3,3};
    vector<int> endTime = {3,4,5,6};
    vector<int> profit = {50,10,40,70};
    // vector<int> startTime = {1,2,3,4,6};
    // vector<int> endTime = {3,5,10,6,9};
    // vector<int> profit = {20,20,100,70,60};
    // vector<int> startTime = {1,1,1};
    // vector<int> endTime = {2,3,4};
    // vector<int> profit = {5,6,4};

    Solution S;
    cout << S.jobScheduling(startTime, endTime, profit) << endl;
    return 0;
}