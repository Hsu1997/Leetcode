#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int mod = 1e9 + 7;
const int MAX_N = 100001;
long long pow10[MAX_N];

int init = [](){
    pow10[0] = 1;
    for (int i = 1; i < MAX_N; i++) pow10[i] = pow10[i-1] * 10 % mod;
    return 0;
}();

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<long long> concatenated(n + 1);
        vector<int> acc(n + 1);
        vector<int> cnt(n + 1);
        for (int i = 0; i < n; i++){
            int d = s[i] - '0';
            if (d > 0) concatenated[i + 1] = (concatenated[i] * 10 + d) % mod;
            else concatenated[i + 1] = concatenated[i];
            acc[i + 1] = acc[i] + d;
            cnt[i + 1] = cnt[i] + (d > 0);
        }
        int q = queries.size();
        vector<int> ans(q);
        for (int i = 0; i < q; i++){
            int s = queries[i][0];
            int e = queries[i][1] + 1;
            int length = cnt[e] - cnt[s];
            long long x = (concatenated[e] - (concatenated[s] * pow10[length]) % mod + mod) % mod;
            ans[i] = (x * (acc[e] - acc[s])) % mod;
        }
        return ans;
    }
};

int main(){
    // string s = "10203004";
    // vector<vector<int>> queries = {{0,7},{1,3},{4,6}};
    // string s = "1000";
    // vector<vector<int>> queries = {{0,3},{1,1}};
    string s = "9876543210";
    vector<vector<int>> queries = {{0,9}};
    Solution S;
    vector<int> ans = S.sumAndMultiply(s, queries);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}