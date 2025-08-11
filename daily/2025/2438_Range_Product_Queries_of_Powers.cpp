#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;
    long long powmod(long long base, int e){
        long long res = 1;
        while(e){
            if (e % 2) res = (res * base) % mod;
            base = (base * base) % mod;
            e >>= 1;
        }
        return res;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> power;
        int pow = 0;
        while(n){
            if (n & 1) power.push_back(pow);
            n >>= 1;
            pow++;
        }
        int s = power.size();
        for (int i = 1; i < s; i++) power[i] += power[i-1];
        int q = queries.size();
        vector<int> ans(q);
        for (int i = 0; i < q; i++){
            int h = queries[i][0];
            int t = queries[i][1];
            int p = power[t];
            if (h > 0) p -= power[h-1];
            ans[i] = powmod(2, p);
        }
        return ans;
    }
};

int main(){
    int n = 15;
    vector<vector<int>> queries = {{0,1},{2,2},{0,3}};
    // int n = 2;
    // vector<vector<int>> queries = {{0,0}};
    Solution S;
    vector<int> ans = S.productQueries(n, queries);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}