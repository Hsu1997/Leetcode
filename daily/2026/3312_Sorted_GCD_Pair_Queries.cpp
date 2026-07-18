#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int m = *max_element(nums.begin(), nums.end());
        vector<long long> cnt(m + 1, 0);
        for (int i : nums) cnt[i]++;
        for (int i = 1; i <= m; i++){
            for (int j = i * 2; j <= m; j += i){
                cnt[i] += cnt[j];
            }
        }
        for (int i = 1; i <= m; i++) cnt[i] = cnt[i] * (cnt[i] - 1) / 2;
        for (int i = m; i > 0; i--){
            for (int j = i * 2; j <= m; j += i){
                cnt[i] -= cnt[j];
            }
        }
        for (int i = 2; i <= m; i++) cnt[i] += cnt[i-1];
        vector<int> ans;
        for (long long q : queries) ans.push_back(lower_bound(cnt.begin(), cnt.end(), q + 1) - cnt.begin());
        return ans;
    }
};

int main(){
    vector<int> nums = {2,3,4};
    vector<long long> queries = {0,2,2};
    // vector<int> nums = {4,4,2,1};
    // vector<long long> queries = {5,3,1,0};
    // vector<int> nums = {2,2};
    // vector<long long> queries = {0,0};
    Solution S;
    vector<int> ans = S.gcdValues(nums, queries);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}