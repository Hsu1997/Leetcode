#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long mod = 1e9 + 7;
    int longpow(long long base, long long pow){
        long long res = 1;
        while(pow){
            if (pow % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            pow /= 2;
        }
        return res;
    }
    int reversemul(int x){
        return longpow(1LL * x, mod - 2);
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int T = sqrt(n);
        vector<vector<vector<int>>> group(T);
        vector<long long> accmul(n + 1, 1);
        for (auto& query : queries){
            int l = query[0];
            int r = query[1];
            int k = query[2];
            int v = query[3];
            if (k < T){
                group[k].push_back({l, r, v});
            }
            else{
                for (int i = l; i <= r; i += k){
                    nums[i] = (1LL * nums[i] * v) % mod;
                }
            }
        }
        for (int k = 1; k < T; k++){
            vector<long long> accmul(n + T, 1);
            for (auto& query : group[k]){
                int l = query[0];
                int r = query[1];
                int v = query[2];
                accmul[l] = (accmul[l] * v) % mod;
                int right = l + (r - l) / k * k + k;
                accmul[right] = (accmul[right] * reversemul(v)) % mod;
            }
            for (int i = k; i < n; i++){
                accmul[i] = (accmul[i] * accmul[i - k]) % mod;
            }
            for (int i = 0; i < n; i++){
                nums[i] = (1LL * nums[i] * accmul[i]) % mod;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++){
            ans ^= nums[i];
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,1,1};
    vector<vector<int>> queries = {{0,2,1,4}};
    // vector<int> nums = {2,3,1,5,4};
    // vector<vector<int>> queries = {{1,4,2,3},{0,2,1,2}};
    Solution S;
    cout << S.xorAfterQueries(nums, queries) << endl;
    return 0;
}