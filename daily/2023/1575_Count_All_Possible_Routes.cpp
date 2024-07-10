#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> dp(n, vector<int>(fuel+1, 0));
        int mod = 1e9+7;
        dp[start][0] = 1;
        for (int used_fuel = 0; used_fuel < fuel; used_fuel++){
            for (int now_city = 0; now_city < n; now_city++){
                if (dp[now_city][used_fuel] == 0) continue;
                for (int next_city = 0; next_city < n; next_city++){
                    int move_used_fuel = used_fuel + abs(locations[now_city] - locations[next_city]);
                    if (now_city != next_city && move_used_fuel <= fuel){
                        dp[next_city][move_used_fuel] = (dp[next_city][move_used_fuel] + dp[now_city][used_fuel]) % mod;
                    }
                }
            }
        }
        // for (auto i : dp){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }
        int ans = 0;
        for (int i : dp[finish]) ans = (ans + i) % mod;
        return ans;
    }
};

int main(){
    vector<int> locations = {2,3,6,8,4};
    int start = 1;
    int finish = 3;
    int fuel = 5;
    // vector<int> locations = {4,3,1};
    // int start = 1;
    // int finish = 0;
    // int fuel = 6;
    // vector<int> locations = {5,2,1};
    // int start = 0;
    // int finish = 2;
    // int fuel = 3;
    Solution S;
    cout << S.countRoutes(locations, start, finish, fuel) << endl;
    return 0;
}