#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long op = 0;
        priority_queue<pair<int,int>> pq;
        stack<int> sta;
        vector<vector<int>> cnt(n);
        vector<int> pos(n, n);
        for (int left = 0, right = 0; right < n; right++){
            while(!sta.empty() && nums[right] >= nums[sta.top()]){
                pos[sta.top()] = right;
                sta.pop();
            }
            if (!sta.empty()) cnt[sta.top()].push_back(right);
            sta.push(right);
            pq.push({nums[right], right});
            op += max(0, pq.top().first - nums[right]);
            while(op > k){
                for (int i : cnt[left]){
                    op -= 1LL * (nums[left] - nums[i]) * (min(pos[i], right + 1) - i);
                }
                left++;
            }
            while(!pq.empty() && pq.top().second < left) pq.pop();
            ans += right - left + 1;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {6,3,1,2,4,4};
    int k = 7;
    // vector<int> nums = {6,3,1,3,6};
    // int k = 4;
    Solution S;
    cout << S.countNonDecreasingSubarrays(nums, k) << endl;
    return 0;
}