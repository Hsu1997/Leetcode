#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        long long MOD = 1e9 + 7;
        long long base = 873957181;
        vector<long long> p(n + 1);
        vector<long long> h(n + 1);
        p[0] = 1;
        for (int i = 1; i <= n; i++){
            p[i] = p[i-1] * base % MOD;
            h[i] = (h[i-1] * base + nums[i-1] ) % MOD;
        }
        int left = 1;
        int right = n;
        int ans = n;
        while(left <= right){
            int l = left + (right - left) / 2;
            unordered_map<int,int> cnt;
            for (int start = 0; start + l <= n; start++){
                long long res = (h[start + l] - h[start] * p[l] % MOD + MOD) % MOD;
                cnt[res]++;
            }
            bool found = false;
            for (auto [_, c] : cnt){
                if (c == 1){
                    found = true;
                    break;
                }
            }
            if (found){
                ans = l;
                right = l - 1;
            }
            else left = l + 1;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {3,3,3};
    // vector<int> nums = {2,1,2,3,3};
    // vector<int> nums = {1,1,2,2,1};
    Solution S;
    cout << S.smallestUniqueSubarray(nums) << endl;
    return 0;
}