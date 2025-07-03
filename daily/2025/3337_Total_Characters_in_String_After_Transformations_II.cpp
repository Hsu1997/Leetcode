#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<long long>> mul(vector<vector<long long>>& a, vector<vector<long long>>& b){
        int m = a.size();
        int n = a[0].size();
        if (n != b.size()) return {{}};
        int k = b[0].size();
        vector<vector<long long>> ans(m, vector<long long>(k, 0));
        for (int i = 0; i < m; i++){
            for (int j = 0; j < k; j++){
                long long res = 0;
                for (int l = 0; l < n; l++){
                    res += ((a[i][l] * b[l][j]) % mod);
                    res %= mod;
                }
                ans[i][j] = res;
            }
        }
        return ans;
    }
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<vector<long long>> init(26, vector<long long>(1, 0));
        for (char c : s) init[c-'a'][0]++;
        vector<vector<long long>> transformer(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; i++){
            for (int j = 1; j <= nums[i]; j++){
                transformer[(i + j) % 26][i]++;
            }
        }
        vector<vector<long long>> res(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; i++) res[i][i] = 1;
        while(t){
            if (t % 2 == 1) res = mul(res, transformer);
            transformer = mul(transformer, transformer);
            t /= 2;
        }
        vector<vector<long long>> final = mul(res, init);
        long long ans = 0;
        for (int i = 0; i < 26; i++){
            ans = (ans + final[i][0]) % mod;
        }
        return ans;
    }
};

int main(){
    string s = "abcyy";
    int t = 2;
    vector<int> nums = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2};
    // string s = "azbk";
    // int t = 1;
    // vector<int> nums = {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
    Solution S;
    cout << S.lengthAfterTransformations(s, t, nums) << endl;
    return 0;
}