#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// class Solution {
// public:
//     int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
//         int n = stations.size();
//         vector<double> dp(n+1,0);
//         dp[0] = startFuel;
//         // dp[i] = the distance can reach of stop i stations.
//         for (int i = 0; i < n; i++){
//         // if we stop at ith station
//             int now_station_position = stations[i][0];
//             double now_station_fuel = stations[i][1];
//             for (int j = i; j >= 0; j--){
//             // check if we have already stop i ~ 0 stations.
//                 if (dp[j] >= now_station_position) dp[j+1] = max(dp[j+1], dp[j] + now_station_fuel);
//                 // if we can reach this station, check if the reachable distance increase.
//             }
//             // for (auto i : dp) cout << i << " ";
//             // cout << endl;
//         }
    

//         for (int i = 0; i < n+1; i++) if (dp[i] >= target) return i;
//         return -1;
//     }
// };

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int remain = startFuel;
        int prev = 0;
        int ans = 0;
        // reach each station and consider need or not to refuel.
        for (auto i : stations){
            int distance = i[0];
            int fuel = i[1];
            remain -= (distance - prev);
            prev = distance;
            while(!pq.empty() && remain < 0){
                remain += pq.top();
                pq.pop();
                ans++;
            }
            if (remain < 0) return -1;
            pq.push(fuel);
        }
        remain -= (target - prev);
        while(!pq.empty() && remain < 0){
            remain += pq.top();
            pq.pop();
            ans++;
        }
        if (remain < 0) return -1;
        return ans;
    }
};

int main(){
    // int target = 1;
    // int startFuel = 1;
    // vector<vector<int>> stations = {};

    int target = 100;
    int startFuel = 50;
    vector<vector<int>> stations = {{25,25},{50,50}};

    // int target = 100;
    // int startFuel = 10;
    // vector<vector<int>> stations = {{10,60},{20,30},{30,30},{60,40}};

    // int target = 1000;
    // int startFuel = 83;
    // vector<vector<int>> stations = {{25,27},{36,187},{140,186},{378,6},{492,202},{517,89},{579,234},{673,86},{808,53},{954,49}};

    Solution S;
    cout << S.minRefuelStops(target, startFuel, stations) << endl;
    return 0;
}