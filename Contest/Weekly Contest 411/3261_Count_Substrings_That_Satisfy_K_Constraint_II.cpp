#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        int n = s.length();
        vector<long long> dp(n, 0);
        vector<long long> dp_acc(n, 0);
        int left = 0;
        int count_zero = 0;
        int count_one = 0;
        for (int right = 0; right < n; right++){
            if (s[right] == '0') count_zero++;
            else count_one++;
            while(count_zero > k && count_one > k){
                if (s[left] == '0') count_zero--;
                else count_one--;
                left++;
            }
            dp[right] = right - left + 1;
        }
        dp_acc[0] = dp[0];
        for (int i = 1; i < n; i++) dp_acc[i] = dp[i] + dp_acc[i-1];
        // for (auto i : dp) cout << i << " ";
        // cout << endl;
        vector<long long> ans;
        for (auto query : queries){
            int start = query[0];
            int end = query[1];
            if (start == 0) ans.push_back(dp_acc[end]);
            else{
                long long temp = dp_acc[end] - dp_acc[start-1];
                for (int i = start; i <= end; i++){
                    int curr_start_from_index = i - dp[i] + 1;
                    if (curr_start_from_index >= start) break;
                    else temp -= start - curr_start_from_index;
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};

int main(){
    string s = "0001111";
    int k = 2;
    vector<vector<int>> queries = {{0,6}};
    // string s = "010101";
    // int k = 1;
    // vector<vector<int>> queries = {{0,5},{1,4},{2,3}};
    // string s = "001110001";
    // int k = 3;
    // vector<vector<int>> queries = {{0,8},{1,8}};
    Solution S;
    vector<long long> ans = S.countKConstraintSubstrings(s, k, queries);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}