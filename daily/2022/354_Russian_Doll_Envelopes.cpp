#include <iostream>
#include <vector>

using namespace std;

bool compare_x(vector<int>& v1, vector<int>& v2){
    if (v1[0] != v2[0]) return v1[0] < v2[0];
    return v1[1] > v2[1];
}

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.size() < 2) return envelopes.size();

        sort(envelopes.begin(), envelopes.end(), compare_x);

        vector<int> increasing;
        // for (auto i : envelopes) increasing.push_back(i[1]);
        
        // for (auto i : increasing) cout << i << " ";
        // cout << endl;

        // O(n^2)
        // vector<int> dp(increasing.size(), 1);
        // dp[0] = 1;
        // int ans = 0;
        // for (int i = 1; i < increasing.size(); i++){
        //     for (int j = 0; j < i; j++){
        //         if (increasing[j] < increasing[i]) dp[i] = max(dp[i], dp[j] + 1);
        //     }
        // ans = max(ans, dp[i]);
        // }
        // return ans;
        

        // reference :
        // https://leetcode.com/problems/longest-increasing-subsequence/discuss/1326552/Optimization-From-Brute-Force-to-Dynamic-Programming-Explained!
        int len = 0;
        for (auto ele : envelopes){
            int cur = ele[1];

            if (len == 0 || increasing[len-1] < cur){
                increasing.push_back(cur);
                len++;
            }
            else if (increasing.back() == cur) continue;
            else{
                *lower_bound(increasing.begin(), increasing.end(), cur) = cur;
            }
        }

        // for (auto i : increasing) cout << i << " ";
        // cout << endl;

        return len;
    }
};

int main(){
    // vector<vector<int>> envelopes = {{5,4},{6,4},{6,7},{2,3}};
    // vector<vector<int>> envelopes = {{30,50},{12,2},{3,4},{12,15}};
    // vector<vector<int>> envelopes = {{1,3},{3,5},{6,7},{6,8},{8,4},{9,5}};
    vector<vector<int>> envelopes = {{15,8},{2,20},{2,14},{4,17},{8,19},{8,9},{5,7},{11,19},{8,11},{13,11},{2,13},{11,19},{8,11},{13,11},{2,13},{11,19},{16,1},{18,13},{14,17},{18,19}};
    Solution S;
    cout << S.maxEnvelopes(envelopes) << endl;
    return 0;
}