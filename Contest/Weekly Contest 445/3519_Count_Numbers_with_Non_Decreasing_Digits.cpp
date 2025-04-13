#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;

    string substract_one(string s){
        int n = s.length();
        for (int i = n-1; i >= 0; i--){
            if (s[i] > '0'){
                s[i]--;
                break;
            }
            else s[i] = '9';
        }
        if (s.length() > 1 && s[0] == '0'){
            int i = 0;
            while(s[i] == '0') i++;
            s = s.substr(i);
        }
        return s;
    }

    pair<string, int> divideString(string s, int divisor){
        int n = s.length();
        string result;
        result.reserve(n);
        int remainder = 0;
        for (int i = 0; i < n; i++){
            remainder = remainder * 10 + (s[i] - '0');
            int q = remainder / divisor;
            if (!result.empty() != 0 || q != 0) result.push_back('0' + q);
            remainder %= divisor;
        }
        if (result.empty()) result = "0";
        return {result, remainder};
    }
    string convert_base(string s, int b){
        if (s == "0") return s;
        string ans;
        while(s != "0"){
            auto [result, remainder] = divideString(s, b);
            ans.push_back('0' + remainder);
            s = result;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    long long dp(string& s, int base){
        int n = s.length();
        vector<vector<vector<long long>>> memo(n, vector<vector<long long>>(base, vector<long long>(2, -1)));
        return dfs(s, 0, base, 0, 1, memo);
    }

    long long dfs(string& s, int pos, int base, int prev_digit, bool limited, vector<vector<vector<long long>>>& memo){
        if (pos == s.length()) return 1;
        if (memo[pos][prev_digit][limited] != -1) return memo[pos][prev_digit][limited];
        long long ans = 0;
        int upper_bound = (limited)? (s[pos] - '0') : base - 1;
        for (int d = prev_digit; d <= upper_bound; d++){
            ans = (ans + dfs(s, pos+1, base, d, limited && (d == upper_bound), memo)) % mod;
        }
        return memo[pos][prev_digit][limited] = ans;
    }

    int countNumbers(string l, string r, int b) {
        l = convert_base(substract_one(l), b);
        r = convert_base(r, b);
        // cout << l << endl << r << endl;
        long long countL = dp(l, b);
        long long countR = dp(r, b);
        return (countR - countL + mod) % mod;
    }
};

int main(){
    string l = "23";
    string r = "28";
    int b = 8;
    // string l = "2";
    // string r = "7";
    // int b = 2;
    // string l = "10";
    // string r = "10";
    // int b = 10;
    Solution S;
    cout << S.countNumbers(l, r, b) << endl;
    return 0;
}