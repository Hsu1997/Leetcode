#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int n;
    int k;
    bool odd = false;
    vector<vector<int>> dp;
    vector<vector<int>> track;
    vector<int> power;

    string largestPalindrome(int _n, int _k) {
        n = _n, k = _k;
        if (n % 2 == 1) odd = true;
        dp = vector<vector<int>>(n, vector<int>(k, -1));
        track = vector<vector<int>>(n, vector<int>(k, -1));
        power = vector<int>(n);
        power[0] = 1 % k;
        for (int i = 1; i < n; i++) power[i] = (power[i-1] * 10) % k;
        dfs(0, 0);
        string ans;
        int remainder = 0;
        for (int i = 0; i < n / 2; i++){
            int curr = track[i][remainder];
            ans += curr + '0';
            remainder = (remainder + curr * (power[i] + power[n - 1 - i])) % k;
        }
        string reverse_ans = ans;
        reverse(reverse_ans.begin(), reverse_ans.end());
        if (odd) ans += track[n / 2][remainder] + '0';
        ans += reverse_ans;
        return ans;
    }

    bool dfs(int index, int remainder){
        if (index == n / 2 + odd) return remainder == 0;
        if (dp[index][remainder] != -1) return dp[index][remainder];
        for (int i = 9; i >= 0; i--){
            int add = 0;
            if (odd && index == n / 2) add = (i * power[index]) % k;
            else add = (i * (power[index] + power[n - 1 - index])) % k;
            if (dfs(index + 1, (remainder + add) % k)){
                track[index][remainder] = i;
                return dp[index][remainder] = true;
            }
        }
        return dp[index][remainder] = false;
    }
};

int main(){
    // int n = 3;
    // int k = 5;
    // int n = 1;
    // int k = 4;
    // int n = 5;
    // int k = 6;
    int n = 1000;
    int k = 7;
    Solution S;
    cout << S.largestPalindrome(n, k) << endl;
    return 0;
}