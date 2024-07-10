#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// class Solution {
// public:
//     int tallestBillboard(vector<int>& rods) {
//         // (s1-s2) : h(s1)
//         unordered_map<int,int> dp;
//         dp[0] = 0;
//         for (int i : rods){
//             unordered_map<int,int> new_dp = dp;
//             for (auto p : dp){
//                 int diff = p.first;
//                 int height = p.second;
//                 new_dp[diff+i] = (new_dp.count(diff+i))? max(new_dp[diff+i],height+i) : height+i;
//                 new_dp[diff-i] = (new_dp.count(diff-i))? max(new_dp[diff-i], height) : height;
//             }
//             dp = new_dp;
//         }
//         return dp.count(0)? dp[0] : -1;
//     }
// };

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int s = 0;
        for (int rod : rods) s += rod;
        vector<int> dp(2*s+1, -1);
        dp[s] = 0;
        for (int rod : rods){
            vector<int> new_dp = dp;
            for (int d = 0; d <= 2*s; d++){
                if (dp[d] == -1) continue;
                new_dp[d+rod] = max(new_dp[d+rod], dp[d]+rod);
                new_dp[d-rod] = max(new_dp[d-rod], dp[d]);
            }
            dp = new_dp;
        }
        return dp[s];
    }
};

int main(){
    // vector<int> rods = {1,2,3,6};
    // vector<int> rods = {1,2,3,4,5,6};
    // vector<int> rods = {1,2};
    // vector<int> rods = {140,138,133,162,145,164,145,166,145,154,158};
    // vector<int> rods = {1,2,4,8,16,32,64,128,256,512,50,50,50,150,150,150,100,100,100,123};
    vector<int> rods = {61,45,43,54,40,53,55,47,51,59,42};
    Solution S;
    cout << S.tallestBillboard(rods) << endl;
    return 0;
}