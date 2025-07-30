#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> target(n);
        vector<int> ans(n);
        int curr = 0;
        for (int i = n-1; i >= 0; i--){
            curr |= nums[i];
            target[i] = curr;
        }
        int M = target[0];
        int bit = 0;
        if (M == 0) return vector<int>(n, 1);
        while(M > 0){
            M /= 2;
            bit++;
        }
        vector<int> cnt(bit, 0);
        int end = -1;
        for (int i = 0; i < n; i++){
            int T = target[i];
            int curr_or = 0;
            for (int k = 0; k < bit; k++) if (cnt[k]) curr_or += (1 << k);
            while(curr_or < T || end < i){
                end++;
                for (int k = 0; k < bit; k++) if (nums[end] & (1 << k)) cnt[k]++;
                curr_or |= nums[end];
            }
            ans[i] = end - i + 1;
            for (int k = 0; k < bit; k++) if (nums[i] & (1 << k)) cnt[k]--;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,0,2,1,3};
    // vector<int> nums = {1,2};
    // vector<int> nums = {1,0};
    Solution S;
    vector<int> ans = S.smallestSubarrays(nums);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}